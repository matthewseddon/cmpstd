find_package(Eigen3 REQUIRED)
find_package(RDKit REQUIRED)

add_library(tools tools.cpp)
target_link_libraries(tools PUBLIC cxx_setup Eigen3::Eigen RDKit::RDGeneral RDKitSmilesParse)
