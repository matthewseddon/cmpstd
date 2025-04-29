#include <cmpstd/service/service.h>
#include <cmpstd/tools/tools.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/support/status.h>
#include <string>
#include "proto/cmpstd.grpc.pb.h"
#include "proto/cmpstd.pb.h"

namespace cmpstd { 
namespace service { 
grpc::Status StandardizeMoleculeImpl::runStandardize(grpc::ServerContext* context, 
                                  const Molecule* request,
                                  Molecule* response) {
    std::cout << "Called runStandardize \n";
    std::string out_smiles = cmpstd::tools::StandardizeSmiles(request->smiles());
    response->set_id(request->id());
    response->set_smiles(out_smiles); 

    return grpc::Status::OK;
    }
} //namespace service
} //namespace cmpstd
