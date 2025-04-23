add_executable(cmpstd_server cmpstd_server.cpp)
target_link_libraries(cmpstd_server PRIVATE service cxx_setup)
add_executable(print_hello print_hello.cpp)
target_link_libraries(print_hello PRIVATE tools cxx_setup)
