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

        // A length function makes more sense for
        // the vector class. Although `n_rows()` and 
        // `n_cols()` can still be called from `rowvec`
        // instance.
        int len() const { return this->n_cols(); }

        // Accessor.
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
    
    // Overwrite the matrix inherited `operator*`
    // so that a scalar is returned when a `rowvec` and
    // `colvec` are multiplied.
    template<class T>
    T operator*(const rowvec<T> & x, const colvec<T> & y) {
        // Use the inherited matrix operator defined in the `mtx` namespace.
        mtx::matrix<T> a = mtx::operator*(x,y);
        // Grab the only entry.
        T z = a(0,0);
        // And return it.
        return z;
    }
}

#endif
