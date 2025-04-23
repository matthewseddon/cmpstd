#include <grpcpp/grpcpp.h>
#include <iostream>
#include <string>
#include "proto/cmpstd.grpc.pb.h"
#include "proto/cmpstd.pb.h"

namespace cmpstd { 
namespace service { 
class StandardizeMoleculeImpl final : public StandardizeMolecule::Service {
  ::grpc::Status runStandardize(::grpc::ClientContext* context, const ::Molecule& request, ::Molecule* response) {
    std::cout << "Called runStandardize \n";
    response->set_id(request.id());
    response->set_smiles("SMILES");    

    return grpc::Status::OK;
    }
};
} //namespace service
} //namespace cmpstd
