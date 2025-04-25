#include <grpcpp/grpcpp.h>
#include <cmpstd/service/service.h>

int main() {
  cmpstd::service::StandardizeMoleculeImpl std_service;
  grpc::ServerBuilder builder;
  builder.AddListeningPort("0.0.0.0:9999", grpc::InsecureServerCredentials());
  builder.RegisterService(&std_service);
 
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  server->Wait();
  return 0;
}
