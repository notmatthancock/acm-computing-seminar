#include <iostream>
#include <cstdlib>
#include "vector.h"

namespace vec {
  vector::vector(unsigned len) {
    this->length = len;
    this->data = new double[len];
    // Initialize data to zeros.
    for(int i=0; i < this->len(); i++) { this->data[i] = 0.0; }
  }

  vector::~vector() {
    delete [] this->data;
  }

  unsigned vector::len() {
    return this->length;
  }

  double & vector::element(unsigned i) {
    #ifndef NDEBUG
    check_index(i);
    #endif
    return this->data[i];
  }

  void vector::print() {
    for(int i=0; i < this->len(); i++) {
      std::cout << this->data[i] << '\n';
    }
  }

  void vector::check_index(unsigned i) {
    if (i < 0 || i >= this->length) {
      std::cerr << "ERROR: index, " << i << ", is out-of-bounds.\n"
                << "(valid indices are 0-" << (this->length-1) << ")\n";
      exit(1);
    }
  }
}
