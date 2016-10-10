#include "diag.h"

int main() {
    mtx::diag<double> D(4);
    D(3,0) = 3;

    for(int i=0; i < D.n_rows(); i++) {
        for(int j=0; j < D.n_cols()+1; j++) {
            std::cout << D(i,j) << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
