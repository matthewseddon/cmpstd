find_package(RDKit REQUIRED)

add_library(tools tools.cpp)
target_link_libraries(tools PUBLIC cxx_setup RDKit::RDGeneral RDKitSmilesParse RDKitMolStandardize)
