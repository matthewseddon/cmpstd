cmake_minimum_required(VERSION 3.28)
project(cmpstd VERSION 0.0.1
               DESCRIPTION "A small utility for compound standardization"
               LANGUAGES CXX)

# set build type for debug by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug1 CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup
    INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_20)

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

find_package(RDKit REQUIRED)
add_executable(service service.cc)
target_link_libraries(service PUBLIC cxx_setup protolib RDKit::RDGeneral RDKitMolStandardize RDKitSmilesParse)
