#include <cmpstd/service/service.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/support/status.h>
#include "proto/cmpstd.grpc.pb.h"
#include "proto/cmpstd.pb.h"

namespace cmpstd { 
namespace service { 
grpc::Status StandardizeMoleculeImpl::runStandardize(grpc::ServerContext* context, 
                                  const Molecule* request,
                                  Molecule* response) {
    std::cout << "Called runStandardize \n";
    response->set_id(request->id());
    response->set_smiles("SMILES");    

    return grpc::Status::OK;
    }
} //namespace service
} //namespace cmpstd
