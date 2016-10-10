#ifndef VECTORS_H
#define VECTORS_H

#include "matrix.h"

namespace vec {
    // Row vector class inherits from the matrix class.
    template<class T>
    class rowvec : public mtx::matrix<T> {
    public:
        // Constructor.
        rowvec(int n) : mtx::matrix<T>(1, n) {}

        // A length function.
        int len() const { return this->n_cols(); }

        // Accessors.
        T & operator()(int i) const { return mtx::matrix<T>::operator()(0, i); }
        // Add [] as a possibility, too.
        T & operator[](int i) const { return (*this)(i); }
    };
    
    // Column vector class also inherits from the matrix class.
    template<class T>
    class colvec : public mtx::matrix<T> {
    public:
        // Constructor.
        colvec(int n) : mtx::matrix<T>(n, 1) {}

        // A length function.
        int len() const { return this->n_rows(); }

        // Accessor.
        T & operator()(int i) const { return mtx::matrix<T>::operator()(i, 0); }
        // Add [] as a possibility, too.
        T & operator[](int i) const { return (*this)(i); }
    };
}

#endif
