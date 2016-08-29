#include "my_library.h"

// Implementation of `linspace`.
double * my_namespace::linspace(double start, double stop, int n_points) {
  double * arr = new double [n_points];
  double dx = (stop-start) / (n_points-1.0);

  for(int i=0; i < n_points; i++) {
    arr[i] = start + i*dx;
  }

  return arr;
}

// Implementation of `print_array`.
void my_namespace::print_array(double * arr, int arr_len) {
  for(int i=0; i < arr_len; i++) {
    std::cout << arr[i] << "\n";
  }
}
