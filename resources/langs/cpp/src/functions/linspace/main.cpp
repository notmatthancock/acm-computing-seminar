#include <iostream>

// This is the function declaration.
// You should describe the functions arguments
// and what is returned by the function in comments
// near the declaration.
//
// `linspace` returns an array of doubles containing
// `n_points` entries which are equally-spaced, starting
// at `start` and ending at `stop`.
double * linspace(double start, double stop, int n_points);

// `void` is a function with no return type.
// `print_array` takes an array and prints it to std out.
void print_array(double * arr, int arr_len);

int main() {
  double * xs = linspace(-1, 1, 5);
  print_array(xs, 5);
  delete [] xs;

  return 0;
}

// Implementation of `linspace`.
double * linspace(double start, double stop, int n_points) {
  double * arr = new double [n_points];
  double dx = (stop-start) / (n_points-1.0);

  for(int i=0; i < n_points; i++) {
    arr[i] = start + i*dx;
  }

  return arr;
}

// Implementation of `print_array`.
void print_array(double * arr, int arr_len) {
  for(int i=0; i < arr_len; i++) {
    std::cout << arr[i] << "\n";
  }
}
