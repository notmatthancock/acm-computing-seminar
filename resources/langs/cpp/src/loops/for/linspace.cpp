#include <iostream>





int main() {
int length = 11;
double x[length];

for(int i=0; i < length; i++) {
  // Assign to each array component.
  x[i] = (double) i / (length - 1);

  // Print the current component.
  std::cout << "x[" << i << "] = " << x[i] << std::endl;
}
return 0;
}
