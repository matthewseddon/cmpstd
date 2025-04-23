#include <grpcpp/grpcpp.h>
#include <grpcpp/server_context.h>
#include <iostream>
#include <string>
#include "proto/cmpstd.grpc.pb.h"
#include "proto/cmpstd.pb.h"

namespace cmpstd {
namespace service {
class StandardizeMoleculeImpl final 
    : public StandardizeMolecule::Service {
  ::grpc::Status runStandardize(::grpc::ServerContext* context, const ::Molecule* request, ::Molecule* response) override;
};
} //namespace service
} //namespace cmpstd
