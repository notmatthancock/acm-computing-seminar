#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <iostream>

namespace my_namespace {
    // `linspace` returns an array of doubles containing
    // `n_points` entries which are equally-spaced, starting
    // at `start` and ending at `stop`.
    double * linspace(double start, double stop, int n_points);

    // `void` is a function with no return type.
    // `print_array` takes an array and prints it to std out.
    void print_array(double * arr, int arr_len);
}

#endif
