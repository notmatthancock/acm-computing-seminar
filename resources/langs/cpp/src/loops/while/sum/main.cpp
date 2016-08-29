#include <iostream>
#include <cstdio>





int main() {
double sum = 0.0;
double base = 0.5;
double pow = base; // initialize to base^1
double tol = 1e-4;
int iter = 1;

while((1-sum) >= tol) {
  // Add `pow` to `sum`.
  sum += pow;
  // Update `pow` by one power of `base`.
  pow *= base;

  printf("Iter: %03d, Sum: %.5f, Abs Err: %.5f\n", iter, sum, 1-sum); 

  // Update the `iter` val by 1.
  iter += 1;
}
return 0;
}
