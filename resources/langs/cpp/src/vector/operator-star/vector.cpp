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

  vector::vector(const vector & src) {
    this->length = src.len();
    this->data = new double[this->len()];

    // Copy over the data.
    for(int i=0; i < this->len(); i++) {
      this->data[i] = src[i];
    }
  }

  vector::~vector() {
    delete [] this->data;
  }

  unsigned vector::len() const {
    return this->length;
  }

  double & vector::operator[](unsigned i) const {
    #ifndef NDEBUG
    check_index(i);
    #endif
    return this->data[i];
  }

  vector & vector::operator=(const vector & src) {
    // Delete the old data.
    delete [] this->data;

    // Initialize the new data.
    this->length = src.len();
    this->data = new double[this->len()];

    // Copy over the new data.
    for(int i=0; i < this->len(); i++) {
      this->data[i] = src[i];
    }

    return *this;
  }

  vector operator*(const vector & v, double s) {
      // Copy v to start.
      vector result = v;
      // Then multiply all entries by scalar, s.
      for(int i=0; i < v.len(); i++) {
          result[i] *= s;
      }
      return result;
  }
        
  vector operator*(double s, const vector & v) {
      return v*s;
  }

  void vector::print() const {
    for(int i=0; i < this->len(); i++) {
      std::cout << this->data[i] << '\n';
    }
  }

  void vector::check_index(unsigned i) const {
    if (i < 0 || i >= this->length) {
      std::cerr << "ERROR: index, " << i << ", is out-of-bounds.\n"
                << "(valid indices are 0-" << (this->length-1) << ")\n";
      exit(1);
    }
  }
}
