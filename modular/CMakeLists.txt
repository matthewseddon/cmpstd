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
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR})

add_subdirectory(${PROJECT_NAME})
add_subdirectory(run)
