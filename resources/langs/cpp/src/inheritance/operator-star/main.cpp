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

    float a = x*y;
    std::cout << a << "\n";

    return 0;
}
