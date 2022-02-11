/*
 * Copyright 2022 Google LLC
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

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: firestore/local/document_overlay.proto

#include "firestore/local/document_overlay.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_google_2ffirestore_2fv1_2fwrite_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<5> scc_info_Write_google_2ffirestore_2fv1_2fwrite_2eproto;
namespace firestore {
namespace client {
class DocumentOverlayDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<DocumentOverlay> _instance;
} _DocumentOverlay_default_instance_;
}  // namespace client
}  // namespace firestore
static void InitDefaultsscc_info_DocumentOverlay_firestore_2flocal_2fdocument_5foverlay_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::firestore::client::_DocumentOverlay_default_instance_;
    new (ptr) ::firestore::client::DocumentOverlay();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::firestore::client::DocumentOverlay::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_DocumentOverlay_firestore_2flocal_2fdocument_5foverlay_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_DocumentOverlay_firestore_2flocal_2fdocument_5foverlay_2eproto}, {
      &scc_info_Write_google_2ffirestore_2fv1_2fwrite_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_firestore_2flocal_2fdocument_5foverlay_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_firestore_2flocal_2fdocument_5foverlay_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_firestore_2flocal_2fdocument_5foverlay_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_firestore_2flocal_2fdocument_5foverlay_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::firestore::client::DocumentOverlay, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::firestore::client::DocumentOverlay, largest_batch_id_),
  PROTOBUF_FIELD_OFFSET(::firestore::client::DocumentOverlay, overlay_mutation_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::firestore::client::DocumentOverlay)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::firestore::client::_DocumentOverlay_default_instance_),
};

const char descriptor_table_protodef_firestore_2flocal_2fdocument_5foverlay_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n&firestore/local/document_overlay.proto"
  "\022\020firestore.client\032\037google/firestore/v1/"
  "write.proto\032\037google/protobuf/timestamp.p"
  "roto\"a\n\017DocumentOverlay\022\030\n\020largest_batch"
  "_id\030\001 \001(\005\0224\n\020overlay_mutation\030\002 \001(\0132\032.go"
  "ogle.firestore.v1.WriteB/\n#com.google.fi"
  "rebase.firestore.protoP\001\242\002\005FSTPBb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_deps[2] = {
  &::descriptor_table_google_2ffirestore_2fv1_2fwrite_2eproto,
  &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_sccs[1] = {
  &scc_info_DocumentOverlay_firestore_2flocal_2fdocument_5foverlay_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_once;
static bool descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto = {
  &descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_initialized, descriptor_table_protodef_firestore_2flocal_2fdocument_5foverlay_2eproto, "firestore/local/document_overlay.proto", 280,
  &descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_once, descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_sccs, descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_firestore_2flocal_2fdocument_5foverlay_2eproto::offsets,
  file_level_metadata_firestore_2flocal_2fdocument_5foverlay_2eproto, 1, file_level_enum_descriptors_firestore_2flocal_2fdocument_5foverlay_2eproto, file_level_service_descriptors_firestore_2flocal_2fdocument_5foverlay_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_firestore_2flocal_2fdocument_5foverlay_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_firestore_2flocal_2fdocument_5foverlay_2eproto), true);
namespace firestore {
namespace client {

// ===================================================================

void DocumentOverlay::InitAsDefaultInstance() {
  ::firestore::client::_DocumentOverlay_default_instance_._instance.get_mutable()->overlay_mutation_ = const_cast< ::google::firestore::v1::Write*>(
      ::google::firestore::v1::Write::internal_default_instance());
}
class DocumentOverlay::_Internal {
 public:
  static const ::google::firestore::v1::Write& overlay_mutation(const DocumentOverlay* msg);
};

const ::google::firestore::v1::Write&
DocumentOverlay::_Internal::overlay_mutation(const DocumentOverlay* msg) {
  return *msg->overlay_mutation_;
}
void DocumentOverlay::clear_overlay_mutation() {
  if (GetArenaNoVirtual() == nullptr && overlay_mutation_ != nullptr) {
    delete overlay_mutation_;
  }
  overlay_mutation_ = nullptr;
}
DocumentOverlay::DocumentOverlay()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:firestore.client.DocumentOverlay)
}
DocumentOverlay::DocumentOverlay(const DocumentOverlay& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from._internal_has_overlay_mutation()) {
    overlay_mutation_ = new ::google::firestore::v1::Write(*from.overlay_mutation_);
  } else {
    overlay_mutation_ = nullptr;
  }
  largest_batch_id_ = from.largest_batch_id_;
  // @@protoc_insertion_point(copy_constructor:firestore.client.DocumentOverlay)
}

void DocumentOverlay::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_DocumentOverlay_firestore_2flocal_2fdocument_5foverlay_2eproto.base);
  ::memset(&overlay_mutation_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&largest_batch_id_) -
      reinterpret_cast<char*>(&overlay_mutation_)) + sizeof(largest_batch_id_));
}

DocumentOverlay::~DocumentOverlay() {
  // @@protoc_insertion_point(destructor:firestore.client.DocumentOverlay)
  SharedDtor();
}

void DocumentOverlay::SharedDtor() {
  if (this != internal_default_instance()) delete overlay_mutation_;
}

void DocumentOverlay::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const DocumentOverlay& DocumentOverlay::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_DocumentOverlay_firestore_2flocal_2fdocument_5foverlay_2eproto.base);
  return *internal_default_instance();
}


void DocumentOverlay::Clear() {
// @@protoc_insertion_point(message_clear_start:firestore.client.DocumentOverlay)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == nullptr && overlay_mutation_ != nullptr) {
    delete overlay_mutation_;
  }
  overlay_mutation_ = nullptr;
  largest_batch_id_ = 0;
  _internal_metadata_.Clear();
}

const char* DocumentOverlay::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 largest_batch_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          largest_batch_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .google.firestore.v1.Write overlay_mutation = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_overlay_mutation(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* DocumentOverlay::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:firestore.client.DocumentOverlay)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 largest_batch_id = 1;
  if (this->largest_batch_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_largest_batch_id(), target);
  }

  // .google.firestore.v1.Write overlay_mutation = 2;
  if (this->has_overlay_mutation()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::overlay_mutation(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:firestore.client.DocumentOverlay)
  return target;
}

size_t DocumentOverlay::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:firestore.client.DocumentOverlay)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .google.firestore.v1.Write overlay_mutation = 2;
  if (this->has_overlay_mutation()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *overlay_mutation_);
  }

  // int32 largest_batch_id = 1;
  if (this->largest_batch_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_largest_batch_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void DocumentOverlay::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:firestore.client.DocumentOverlay)
  GOOGLE_DCHECK_NE(&from, this);
  const DocumentOverlay* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<DocumentOverlay>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:firestore.client.DocumentOverlay)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:firestore.client.DocumentOverlay)
    MergeFrom(*source);
  }
}

void DocumentOverlay::MergeFrom(const DocumentOverlay& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:firestore.client.DocumentOverlay)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_overlay_mutation()) {
    _internal_mutable_overlay_mutation()->::google::firestore::v1::Write::MergeFrom(from._internal_overlay_mutation());
  }
  if (from.largest_batch_id() != 0) {
    _internal_set_largest_batch_id(from._internal_largest_batch_id());
  }
}

void DocumentOverlay::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:firestore.client.DocumentOverlay)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DocumentOverlay::CopyFrom(const DocumentOverlay& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:firestore.client.DocumentOverlay)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DocumentOverlay::IsInitialized() const {
  return true;
}

void DocumentOverlay::InternalSwap(DocumentOverlay* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(overlay_mutation_, other->overlay_mutation_);
  swap(largest_batch_id_, other->largest_batch_id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata DocumentOverlay::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace client
}  // namespace firestore
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::firestore::client::DocumentOverlay* Arena::CreateMaybeMessage< ::firestore::client::DocumentOverlay >(Arena* arena) {
  return Arena::CreateInternal< ::firestore::client::DocumentOverlay >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>