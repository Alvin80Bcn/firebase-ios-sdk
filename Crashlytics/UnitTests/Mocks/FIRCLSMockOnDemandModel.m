// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import "Crashlytics/UnitTests/Mocks/FIRCLSMockOnDemandModel.h"

@interface FIRCLSMockOnDemandModel ()

@property(nonatomic, readonly) uint32_t uploadRate;

@end

@implementation FIRCLSMockOnDemandModel

- (instancetype)initWithOnDemandUploadRate:(int)uploadRate
                                      base:(double)base
                              stepDuration:(int)stepDuration
                                sleepBlock:(void (^)(int))sleepBlock {
  self = [super initWithOnDemandUploadRate:uploadRate base:base stepDuration:stepDuration];
  if (!self) {
    return nil;
  }
  _uploadRate = uploadRate;
  _sleepBlock = sleepBlock;
  return self;
}
- (void)setQueueToFull {
  [self setQueuedOperationsCount:self.uploadRate];
}

- (void)setQueueToEmpty {
  [self setQueuedOperationsCount:0];
}

- (int)getQueueMax {
  return self.uploadRate;
}

- (void)implementOnDemandUploadDelay:(int)delay {
  _sleepBlock(delay);
}

@end
