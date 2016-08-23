#ifndef VECTOR_H
#define VECTOR_H

namespace vec {
  class vector {
  public:
    // Constructor. This function is called when the object is created.
    vector(unsigned len);

    // Destructor. This function is called when the object is destroyed.
    ~vector();

    // length accessor.
    unsigned len();

    // data accessor.
    double & element(unsigned i);

    // Simple print function.
    void print();

  private:
    unsigned length;
    double * data;
    void check_index(unsigned i);
  };
}
#endif
