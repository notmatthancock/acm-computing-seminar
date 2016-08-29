#include <iostream>





int main() {
int n_rows = 4;
int n_cols = 3;

// Row-major matrix array.
double matrix [n_rows*n_cols];

// temporary index.
int k;

for(int i=0; i < n_rows; i++) {
  for(int j=0; j < n_cols; j++) {
    // Convert the (i,j) matrix index to the "flat" row-major index.
    k = i*n_cols + j;

    // Assign a value of 1.0 to the diagonal,
    // 2 to the off-diagonal, and 0 otherwise.
    if (i == j) {
      matrix[k] = 1.0;
    }
    else if ((i == (j+1)) || (i == (j-1))){
      matrix[k] = 2.0;
    }
    else {
      matrix[k] = 0.0;
    }
  }
}


// Print the matrix elements.
for(int i=0; i < n_rows; i++) {
  for(int j=0; j < n_cols; j++) {
    k = i*n_cols + j;

    std::cout << matrix[k];
    if (j != (n_cols-1)) {
      std::cout << ", ";
    }
  }

  if (i != (n_rows-1)) {
    std::cout << "\n";
  }
}
return 0;
}
