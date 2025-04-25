#include <eigen3/Eigen/Dense>
#include <iostream>

#include "sum.hpp"

int main () {
  std::cout << "hello you!\n";

  std::cout << sum (3.5, 1.9) << "\n";

  Eigen::Vector2d v{ 1.2, 4.5 };
  std::cout << v.norm () << "\n";
}
