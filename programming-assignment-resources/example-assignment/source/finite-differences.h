#ifndef FINITE_DIFFERENCES_H
#define FINITE_DIFFERENCES_H

namespace fdiff {
    // Compute the forward difference of `func` at `x`, using step, `h`.
    double forward(double (*func)(double t), double x, double h) {
        return (func(x+h)-func(x)) / h;
    }

    // Compute the backward difference of `func` at `x`, using step, `h`.
    double backward(double (*func)(double t), double x, double h) {
        return (func(x)-func(x-h)) / h;
    }

    // Compute the central difference of `func` at `x`, using step, `h`.
    double central(double (*func)(double t), double x, double h) {
        return 0.5 * (func(x+h)-func(x-h)) / h;
    }
}

#endif
