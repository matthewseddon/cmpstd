#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include <rdkit/GraphMol/GraphMol.h>
#include <rdkit/GraphMol/SmilesParse/SmilesParse.h>
#include <rdkit/GraphMol/MolStandardize/MolStandardize.h>
#include "proto/cmpstd.grpc.pb.h"
#include "proto/cmpstd.pb.h"

class StandardizeMoleculeImpl final : public StandardizeMolecule::Service {
  public:
    grpc::Status runStandardize(grpc::ServerContext* context,
                                const Molecule* request,
                                Molecule* response) override {
      std::cout << "Called runStandardize \n";
      std::string std_smiles = RDKit::MolStandardize::standardizeSmiles(request->smiles());
      response->set_id(request->id());
      response->set_smiles(std_smiles);

      return grpc::Status::OK;
  }
};


void RunServer(const std::string listening_port) {
  StandardizeMoleculeImpl std_service;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(listening_port, grpc::InsecureServerCredentials());
  builder.RegisterService(&std_service);
 
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server running and listening on " << listening_port << "\n";
  server->Wait();
}

int main() {
  std::string listening_port("0.0.0.0:9999");
  RunServer(listening_port);

  return 0;
}
