#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed a random number generator.
  srand(123);

  // rand() produces a random integer between 0 and RAND_MAX.
  double num = rand() / ((double) RAND_MAX);

  std::cout << "num: " << num << "\n";

  if (num < 0.5) {
    std::cout << "num was less than 0.5.\n";
  }
  else {
    std::cout << "num was greater than 0.5.\n";
  }

  // Do it again.
  num = rand() / ((double) RAND_MAX);

  std::cout << "num: " << num << "\n";

  if (num < 0.5) {
    std::cout << "num was less than 0.5.\n";
  }
  else {
    std::cout << "num was greater than 0.5.\n";
  }

  return 0;
}
