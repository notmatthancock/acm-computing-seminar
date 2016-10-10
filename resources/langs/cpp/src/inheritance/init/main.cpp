#include <iostream>
#include "matrix.h"
#include "vectors.h"

int main() {
    vec::rowvec<float> x(5);
    vec::colvec<float> y(5);

    for(int i=0; i < x.len(); i++) {
        x(i) = i;
        y[i] = -i; // elements may be accessed with either operator.
    }

    // `rowvec` and `colvec` inherit from `matrix`,
    // so `operator*` is well-defined if the shapes
    // align, which always do for `rowvec` * `colvec`.
    // However, the result is a `matrix` object.
    mtx::matrix<float> a = x*y;

    std::cout << a.n_rows() << ", " << a.n_cols()
              << " ... " << a(0,0) << "\n";

    return 0;
}
