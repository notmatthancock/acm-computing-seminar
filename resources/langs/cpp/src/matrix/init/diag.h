#ifndef DIAG_H
#define DIAG_H

#include "matrix.h"

namespace mtx {
    template<class T>
    class diag : public matrix<T> {
    public:
        // Constructor.
        diag(int d) {
            this->m = this->n = d;
            this->data = new T[d];
            for(int i=0; i < d; i++) this->data[i] = T(0);
        }

        // Copy constructor.
//        diag(const diag & src) : diag(src.n_rows()) {
//            for(int i=0; i < src.n_rows(); i++){
//                this->data[i] = src.data[i];
//            }
//        }

        // Element accessor.
        T & operator()(int i, int j) {
            return (i==j) ? matrix<T>::operator()(i,j) : this->off_diag;
        }

        T off_diag = 0;
    };
}

#endif
