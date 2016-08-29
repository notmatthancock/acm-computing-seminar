#include <iostream>
#include <limits>

int main() {
  float a; //  Declare a single precision float.
  double b; // Declare a double precision float.

  // Print the max value of a float type.
  std::cout << std::numeric_limits<float>::max() << std::endl;

  // Print the max value of a double type.
  std::cout << std::numeric_limits<double>::max() << std::endl;

  // Print machine epsilon of a float type.
  std::cout << std::numeric_limits<float>::epsilon() << std::endl;

  // Print machine epsilon of a double type.
  std::cout << std::numeric_limits<double>::epsilon() << std::endl;

  return 0;
}
