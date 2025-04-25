# cmpstd
This project demonstrates a simple compound standardization service that can be run on the cloud.

The service is written in C++ and uses gRPC for the RPC implementation and RDKit for the simple standardization functionality. In practice a production system would most likely have a more elaborate standardization procedure. However, for the use case here we just use the simplest `StandardizeSmiles` call in RDKit.

The service can be build in Docker ensuring that it can be deployed on a cloud system for production use.

Finally, an illustrative Python client has been written to illustrate how this can be incorporated into back end data processing workflows.
