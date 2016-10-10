#include <iostream>
#include "matrix.h"

int main() {
    mtx::matrix<float>  A(10, 10);
    mtx::matrix<double> B(10, 12);

    A(0,0) = 3.14;
    B(2,4) = -2*A(0,0);

    std::cout << A(0,0) << "\n";
    std::cout << B(2,4) << "\n";

    mtx::matrix<double> C = B;

    std::cout << C(2,4) << "\n";

    C(0,12);

    return 0;
}
