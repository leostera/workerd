// Copyright (c) 2017-2022 Cloudflare, Inc.
// Licensed under the Apache 2.0 license found in the LICENSE file or at:
//     https://opensource.org/licenses/Apache-2.0

#pragma once

#include <workerd/io/io-context.h>
#include <workerd/io/worker-interface.capnp.h>
#include <workerd/jsg/jsg.h>

namespace workerd::api {

// An opaque snapshot handle wrapping a capnp capability for cross-DO fork. JS code can hold this
// object and pass it over DO RPC, but cannot inspect or call it. The capability is recovered by
// C++ code on the receiving side via getClient().
//
// The capability is a KJ I/O object, so (like DurableObjectClass's channel) it must be held via
// IoOwn to ensure it is destroyed within the owning IoContext rather than whenever the JS object
// happens to be garbage-collected.
class DurableObjectSnapshot final: public jsg::Object {
 public:
  explicit DurableObjectSnapshot(capnp::Capability::Client client);

  capnp::Capability::Client getClient();

  JSG_RESOURCE_TYPE(DurableObjectSnapshot) {
    // No methods exposed to JS.
  }
  JSG_SERIALIZABLE(rpc::SerializationTag::DURABLE_OBJECT_SNAPSHOT);

  void serialize(jsg::Lock& js, jsg::Serializer& serializer);
  static jsg::Ref<DurableObjectSnapshot> deserialize(
      jsg::Lock& js, rpc::SerializationTag tag, jsg::Deserializer& deserializer);

 private:
  IoOwn<capnp::Capability::Client> client;
};

#define EW_SNAPSHOT_ISOLATE_TYPES api::DurableObjectSnapshot

}  // namespace workerd::api
