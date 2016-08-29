#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator based on the current time.
  srand(time(NULL));

  // rand() produces a random integer between 0 and RAND_MAX.
  double num = rand() / ((double) RAND_MAX);

  std::cout << "num: " << num << "\n";

  if (num >= 0.75) {
    std::cout << "num was between 0.75 and 1.\n";
  }
  else if (num >= 0.5) {
    std::cout << "num was between 0.5 and 0.75.";
  }
  else if (num >= 0.25) {
    std::cout << "num was between 0.25 and 0.5.";
  }
  else {
    std::cout << "num was between 0 and 0.25";
  }

  return 0;
}
