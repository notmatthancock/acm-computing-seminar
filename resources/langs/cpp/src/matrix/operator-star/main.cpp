#include <iostream>
#include "matrix.h"

int main() {
    mtx::matrix<double> A(2,2);
    mtx::matrix<double> B(2,3);

    A(0,0) = A(0,1) = A(1,0) = 1; A(1,1) = -1;

    B(0,0) = B(1,0) = 1;
    B(0,1) = B(1,1) = -1;
    B(0,2) = B(1,2) = 3;


    mtx::matrix<double> C = A*B;

    for(int i=0; i < C.n_rows(); i++) {
        for(int j=0; j < C.n_cols(); j++) {
            std::cout << C(i,j);
            if (j < C.n_cols()-1)
                std::cout << ", ";
        }
        std::cout << "\n";
    }

    B*A;

    return 0;
}
