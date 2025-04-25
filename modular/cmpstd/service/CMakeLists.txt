set(gRPC_DIR /home/matthew/deps CACHE STRING "local gRPC install")
set(Protobuf_DIR /home/matthew/deps CACHE STRING "local Protobuf install")
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

message(STATUS "grpc_cpp_plugin_location: ${grpc_cpp_plugin_location}")

add_library(protolib proto/cmpstd.proto)
target_link_libraries(protolib PUBLIC gRPC::grpc++)
target_include_directories(protolib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET protolib LANGUAGE cpp)
protobuf_generate(TARGET protolib LANGUAGE grpc
                  GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
                  PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")

add_library(service service.cpp)
target_link_libraries(service PUBLIC cxx_setup protolib)
target_include_directories(service PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
