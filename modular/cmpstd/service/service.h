#pragma once
#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H
#include <grpc/grpc.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/support/status.h>

#include "proto/cmpstd.grpc.pb.h"
#include "proto/cmpstd.pb.h"

using grpc::Service;
using grpc::ServerContext;
using grpc::Status;

namespace cmpstd {
namespace service {
class StandardizeMoleculeImpl final 
    : public StandardizeMolecule::Service {
    public:
      Status runStandardize(ServerContext* context,
                                  const Molecule* request,
                                  Molecule* response) override;
};
} //namespace service
} //namespace cmpstd
#endif
