#include <iostream>
#include <cmath>

const double E = std::exp(1.0);

// The function to be integrated.
double func(double x);

// Compute the midpoint rule approximation to
// the definite integral of `f` from `a` to `b`
// using `n` subintervals.
double midpoint_rule(double (*f)(double), double a, double b, int n);


int main() {
  for(int n=2; n <= 20; n += 2) {
    std::cout << "n = " << n << ", "
              << "M_n = " << midpoint_rule(&func, 1, E, n) << "\n";
  }

  return 0;
}

double func(double x) { return 1.0 / x; }

double midpoint_rule(double (*f)(double), double a, double b, int n) {
  double xi;
  double xi_prev = a;
  double dx = (b-a) / n;
  double sum;

  for(int i=1; i <= n; i++) {
    xi = a + i*dx;
    sum += f(0.5*(xi_prev + xi));
    xi_prev = xi;
  }

  return sum*dx;
}
