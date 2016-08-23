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

  vector::vector(vector & src) {
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

  unsigned vector::len() {
    return this->length;
  }

  double & vector::operator[](unsigned i) {
    #ifndef NDEBUG
    check_index(i);
    #endif
    return this->data[i];
  }

  vector & vector::operator=(vector & src) {
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

  vector & vector::operator+(vector & src) {
    #ifndef NDEBUG
    this->check_same_len(src);
    #endif

    vector * result = new vector(this->len());

    for(int i=0; i < this->len(); i++) {
      result->data[i] = this->data[i] + src[i];
    }
    
    return *result;
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

  void vector::check_same_len(vector & src) {
    if (this->len() != src.len()) {
      std::cerr << "ERROR: length mismatch.\n"
                << "(left len: " << this->len() << ", "
                << "right len: " << src.len() << ")\n";
      exit(1);
    }
  }
}
