#include <cmpstd/service/service.h>
#include <grpcpp/grpcpp.h>
#include <iostream>
#include "proto/cmpstd.grpc.pb.h"
#include "proto/cmpstd.pb.h"

namespace cmpstd { 
namespace service { 
class StandardizeMoleculeImpl final : public StandardizeMolecule::Service {
    public:
      grpc::Status runStandardize(grpc::ServerContext* context, 
                                  const Molecule* request,
                                  Molecule* response) override {
    std::cout << "Called runStandardize \n";
    response->set_id(request->id());
    response->set_smiles("SMILES");    

    return grpc::Status::OK;
    }
};
} //namespace service
} //namespace cmpstd
