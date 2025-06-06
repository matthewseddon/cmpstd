# cmpstd
This project demonstrates a simple compound standardization service that can be run on the cloud.

The service is written in C++ and uses gRPC for the RPC implementation and RDKit for the simple standardization functionality. In practice a production system would most likely have a more elaborate standardization procedure. However, for the use case here we just use the simplest `StandardizeSmiles` call in RDKit.

The service can be build in Docker ensuring that it can be deployed on a cloud system for production use.

Finally, an illustrative Python client has been written to illustrate how this can be incorporated into back end data processing workflows.

## Simple Example Service
The build is demonstrated in a multistage `Dockerfile` so that you don't need to build all the code to run the server.
A simple example is provided in the `simple` directory. To build and run this in docker build with
```bash
docker build --tag cmpstd-server --target simple . # build the deployment application
```
Running the application can then be done using port forwarding.
```bash
docker run -it -p 9999:9999 --tag cmpstd-service
```
Then we can use a program like insomnia or grpcurl to run a simple query against the service. 

## Modular Example Service
This modular build replicates the functionality of the simple build but splits the functionality into different modules, which is better suited to a more complex tool.
A build of this in the `Dockerfile` is in the `modular` build.
```bash
docker build --tag cmpstd-server --target modular . # build the deployment application
docker run -it -p 9999:9999 --tag cmpstd-service
```
## Example Python client

