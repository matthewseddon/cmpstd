#include <cmpstd/tools/tools.h>
#include <iostream>
#include <eigen3/Eigen/Dense>

namespace cmpstd { namespace tools {
void PrintHello() { 
    std::cout<< "Hello!" << std::endl; 
    Eigen::Vector2d v{3.0, 4.0};
    std::cout << v.norm() << std::endl;
}
}}
