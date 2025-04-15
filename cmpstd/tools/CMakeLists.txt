find_package(Eigen3 REQUIRED)
# target_link_libraries(hello sum Eigen3::Eigen)
add_library(tools tools.cpp)
target_link_libraries(tools PUBLIC cxx_setup Eigen3::Eigen)
