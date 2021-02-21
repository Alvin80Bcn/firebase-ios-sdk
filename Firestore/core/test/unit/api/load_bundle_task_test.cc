/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <chrono>
#include <mutex>
#include <queue>
#include <thread>

#include "Firestore/core/src/api/load_bundle_task.h"
#include "Firestore/core/src/util/executor.h"
#include "absl/synchronization/blocking_counter.h"
#include "gtest/gtest.h"

namespace firebase {
namespace firestore {
namespace api {

// A very naive implementation of blocking queue, only blocks on `pop()` though.
template <typename T>
class BlockingQueue {
 public:
  bool empty() {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
  }

  void push(T v) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(v);
  }

  T pop() {
    // Spin locks, works for our purpose ¯\_(ツ)_/¯
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
      std::lock_guard<std::mutex> lock(mutex_);
      if (!queue_.empty()) {
        auto result = queue_.front();
        queue_.pop();
        return result;
      }
    }
  }

 private:
  std::queue<T> queue_;
  mutable std::mutex mutex_;
};

std::unique_ptr<util::Executor> CreateUserQueue() {
  return util::Executor::CreateSerial("Testing User Queue");
}

LoadBundleTaskProgress SuccessProgress() {
  return {2, 2, 10, 10, LoadBundleTaskState::Success};
}

LoadBundleTaskProgress Progress(uint32_t documents_loaded,
                                uint64_t bytes_loaded) {
  return {documents_loaded, 2, bytes_loaded, 10,
          LoadBundleTaskState::InProgress};
}

LoadBundleTaskProgress InitialProgress() {
  return Progress(0, 0);
}

TEST(LoadBundleTaskTest, SuccessObserveTriggers) {
  LoadBundleTask task(CreateUserQueue());
  absl::BlockingCounter counter(3);

  auto handle1 = task.ObserveState(LoadBundleTaskState::Success,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, SuccessProgress());
                                     counter.DecrementCount();
                                   });
  auto handle2 = task.ObserveState(LoadBundleTaskState::Success,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, SuccessProgress());
                                     (void)p;
                                     counter.DecrementCount();
                                   });
  auto handle3 = task.ObserveState(LoadBundleTaskState::Success,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, SuccessProgress());
                                     counter.DecrementCount();
                                   });

  task.SetSuccess(SuccessProgress());

  counter.Wait();
}

TEST(LoadBundleTaskTest, RemovesObserverByHandle) {
  LoadBundleTask task(CreateUserQueue());
  absl::BlockingCounter counter(1);

  auto handle1 = task.ObserveState(LoadBundleTaskState::Success,
                                   [&](LoadBundleTaskProgress p) {
                                     (void)p;
                                     FAIL() << "Removed observer is called.";
                                   });
  task.RemoveObserver(handle1);

  auto handle2 = task.ObserveState(LoadBundleTaskState::Success,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, SuccessProgress());
                                     counter.DecrementCount();
                                   });

  task.SetSuccess(SuccessProgress());

  counter.Wait();
}

TEST(LoadBundleTaskTest, ErrorObserveTriggers) {
  LoadBundleTaskProgress error_progress(0, 0, 0, 0, LoadBundleTaskState::Error);
  LoadBundleTask task(CreateUserQueue());
  absl::BlockingCounter counter(3);

  auto handle1 = task.ObserveState(LoadBundleTaskState::Error,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, error_progress);
                                     counter.DecrementCount();
                                   });
  auto handle2 = task.ObserveState(LoadBundleTaskState::Error,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, error_progress);
                                     (void)p;
                                     counter.DecrementCount();
                                   });
  auto handle3 = task.ObserveState(LoadBundleTaskState::Error,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, error_progress);
                                     counter.DecrementCount();
                                   });

  task.SetError();

  counter.Wait();
}

TEST(LoadBundleTaskTest, RemovesObserverByState) {
  LoadBundleTask task(CreateUserQueue());

  auto handle1 = task.ObserveState(LoadBundleTaskState::Error,
                                   [&](LoadBundleTaskProgress p) {
                                     (void)p;
                                     FAIL() << "Removed observer is called.";
                                   });
  task.RemoveObservers(LoadBundleTaskState::Error);
  task.SetError();

  absl::BlockingCounter counter(1);
  LoadBundleTaskProgress error_progress(0, 0, 0, 0, LoadBundleTaskState::Error);
  auto handle2 = task.ObserveState(LoadBundleTaskState::Error,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, error_progress);
                                     counter.DecrementCount();
                                   });

  task.SetError();

  counter.Wait();
}

TEST(LoadBundleTaskTest, ProgressObserveTriggers) {
  LoadBundleTask task(CreateUserQueue());
  absl::BlockingCounter counter(3);

  auto handle1 = task.ObserveState(LoadBundleTaskState::InProgress,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, Progress(1, 5));
                                     counter.DecrementCount();
                                   });
  auto handle2 = task.ObserveState(LoadBundleTaskState::InProgress,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, Progress(1, 5));
                                     counter.DecrementCount();
                                   });
  auto handle3 = task.ObserveState(LoadBundleTaskState::InProgress,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, Progress(1, 5));
                                     counter.DecrementCount();
                                   });

  task.UpdateProgress(Progress(1, 5));

  counter.Wait();
}

TEST(LoadBundleTaskTest, RemovesAllObservers) {
  LoadBundleTask task(CreateUserQueue());

  auto handle1 = task.ObserveState(LoadBundleTaskState::InProgress,
                                   [&](LoadBundleTaskProgress p) {
                                     (void)p;
                                     FAIL() << "Removed observer is called.";
                                   });
  auto handle2 = task.ObserveState(LoadBundleTaskState::InProgress,
                                   [&](LoadBundleTaskProgress p) {
                                     (void)p;
                                     FAIL() << "Removed observer is called.";
                                   });
  auto handle3 = task.ObserveState(LoadBundleTaskState::Error,
                                   [&](LoadBundleTaskProgress p) {
                                     (void)p;
                                     FAIL() << "Removed observer is called.";
                                   });
  task.RemoveAllObservers();

  task.UpdateProgress(Progress(1, 5));
  task.SetError();

  absl::BlockingCounter counter(1);
  auto handle4 = task.ObserveState(LoadBundleTaskState::Success,
                                   [&](LoadBundleTaskProgress p) {
                                     EXPECT_EQ(p, SuccessProgress());
                                     counter.DecrementCount();
                                   });
  task.SetSuccess(SuccessProgress());

  counter.Wait();
}

TEST(LoadBundleTaskTest, ProgressesFireInOrder) {
  LoadBundleTask task(CreateUserQueue());
  BlockingQueue<int> queue;
  task.ObserveState(LoadBundleTaskState::InProgress,
                    [&](LoadBundleTaskProgress p) {
                      (void)p;
                      queue.push(1);
                    });
  task.ObserveState(LoadBundleTaskState::InProgress,
                    [&](LoadBundleTaskProgress p) {
                      (void)p;
                      queue.push(2);
                    });
  task.ObserveState(LoadBundleTaskState::InProgress,
                    [&](LoadBundleTaskProgress p) {
                      (void)p;
                      queue.push(3);
                    });

  task.SetSuccess(SuccessProgress());

  EXPECT_EQ(1, queue.pop());
  EXPECT_EQ(2, queue.pop());
  EXPECT_EQ(3, queue.pop());
}

TEST(LoadBundleTaskTest, ProgressObserverCanAddObserver) {
  LoadBundleTask task(CreateUserQueue());
  BlockingQueue<int> queue;

  task.ObserveState(LoadBundleTaskState::InProgress,
                    [&](LoadBundleTaskProgress p) {
                      (void)p;
                      queue.push(1);

                      task.ObserveState(LoadBundleTaskState::InProgress,
                                        [&](LoadBundleTaskProgress p) {
                                          (void)p;
                                          queue.push(2);
                                        });
                    });

  task.UpdateProgress(SuccessProgress());
  EXPECT_EQ(1, queue.pop());

  task.UpdateProgress(SuccessProgress());
  EXPECT_EQ(1, queue.pop());
  EXPECT_EQ(2, queue.pop());
}

TEST(LoadBundleTaskTest, ProgressObserverCanRemoveObserver) {
  LoadBundleTask task(CreateUserQueue());
  BlockingQueue<int> queue;

  LoadBundleHandle handle1;
  LoadBundleHandle handle2;
  handle1 = task.ObserveState(
      LoadBundleTaskState::InProgress, [&](LoadBundleTaskProgress p) {
        (void)p;
        queue.push(1);
        task.RemoveObserver(handle1);

        handle2 = task.ObserveState(
            LoadBundleTaskState::InProgress, [&](LoadBundleTaskProgress p) {
              (void)p;
              queue.push(2);
              // handle3
              task.ObserveState(LoadBundleTaskState::InProgress,
                                [&](LoadBundleTaskProgress p) {
                                  (void)p;
                                  queue.push(3);
                                  task.RemoveObserver(handle2);
                                });
            });
      });

  // Running handle1, which registers handle2 and removes itself
  task.UpdateProgress(SuccessProgress());
  EXPECT_EQ(1, queue.pop());

  // Running handle2, which registers handle3
  task.UpdateProgress(SuccessProgress());
  EXPECT_EQ(2, queue.pop());

  // Running handle2 and handle3. handle2 registers another handle3, then
  // handle3 removes handle2.
  task.UpdateProgress(SuccessProgress());
  EXPECT_EQ(2, queue.pop());
  EXPECT_EQ(3, queue.pop());

  // Running two handle3
  task.UpdateProgress(SuccessProgress());
  EXPECT_EQ(3, queue.pop());
  EXPECT_EQ(3, queue.pop());
  EXPECT_TRUE(queue.empty());
}

TEST(LoadBundleTaskTest, ProgressObservesUntilSuccess) {
  LoadBundleTask task(CreateUserQueue());
  BlockingQueue<LoadBundleTaskProgress> queue;
  task.ObserveState(LoadBundleTaskState::InProgress,
                    [&](LoadBundleTaskProgress p) { queue.push(p); });

  task.UpdateProgress(InitialProgress());
  EXPECT_EQ(InitialProgress(), queue.pop());

  task.UpdateProgress(Progress(2, 5));
  EXPECT_EQ(Progress(2, 5), queue.pop());

  task.SetSuccess(SuccessProgress());
  EXPECT_EQ(SuccessProgress(), queue.pop());

  EXPECT_TRUE(queue.empty());
}

TEST(LoadBundleTaskTest, ProgressObservesUntilError) {
  LoadBundleTask task(CreateUserQueue());
  BlockingQueue<LoadBundleTaskProgress> queue;
  task.ObserveState(LoadBundleTaskState::InProgress,
                    [&](LoadBundleTaskProgress p) { queue.push(p); });

  task.UpdateProgress(InitialProgress());
  EXPECT_EQ(InitialProgress(), queue.pop());

  task.UpdateProgress(Progress(2, 5));
  EXPECT_EQ(Progress(2, 5), queue.pop());

  task.SetError();
  auto expected = Progress(2, 5);
  expected.set_state(LoadBundleTaskState::Error);
  EXPECT_EQ(expected, queue.pop());

  EXPECT_TRUE(queue.empty());
}

TEST(LoadBundleTaskTest, ProgressObservesInitialError) {
  LoadBundleTask task(CreateUserQueue());
  BlockingQueue<LoadBundleTaskProgress> queue;
  task.ObserveState(LoadBundleTaskState::InProgress,
                    [&](LoadBundleTaskProgress p) { queue.push(p); });

  task.SetError();
  auto expected = LoadBundleTaskProgress();
  expected.set_state(LoadBundleTaskState::Error);
  EXPECT_EQ(expected, queue.pop());

  EXPECT_TRUE(queue.empty());
}

TEST(LoadBundleTaskTest, NoObserversAlsoWork) {
  LoadBundleTask task(CreateUserQueue());

  // No way to observe, simple checking no crashing happens.
  task.UpdateProgress(InitialProgress());
  task.UpdateProgress(Progress(2, 5));
  task.SetSuccess(SuccessProgress());
  task.SetError();
}

}  // namespace api
}  // namespace firestore
}  // namespace firebase