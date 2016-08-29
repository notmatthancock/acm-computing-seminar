#include <cmath>
#include <iostream>

// The function to find the root of.
double func(double x);
// Its derivative.
double dfunc(double x);

// Find the root of `f` using Newton's method,
// starting from `x0` until |f(x)| < `tol` or `max_iters`
// is reached.
//
// Note the first and second arguments are function pointers.
double newton_root(double (*f)(double), double (*df)(double), double x0,
                   double tol, int max_iters, bool print_iters); 

int main() {
  double x = newton_root(&func, &dfunc, 1.0, 1e-6, 1000, true);

  return 0;
}

double func( double x) { return x*x - 2; }
double dfunc(double x) { return 2*x; }

double newton_root(double (*f)(double), double (*df)(double), double x0,
                   double tol, int max_iters, bool print_iters) {
  double x  = x0;
  int iter  = 0;

  while (std::abs(f(x)) > tol && iter < max_iters) {
    if (print_iters) { 
      std::cout << "f(" << x << ") = " << f(x) << "\n";
    }

    // Newton's method update.
    x -= f(x) / df(x);
    iter++;
  }
  
  // One last print if necessary.
  if (print_iters) { 
    std::cout << "f(" << x << ") = " << f(x) << "\n";
  }

  return x;
}
