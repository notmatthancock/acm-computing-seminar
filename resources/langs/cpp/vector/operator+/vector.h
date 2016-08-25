#ifndef VECTOR_H
#define VECTOR_H

namespace vec {
  class vector {
  public:
    // Constructor. This function is called when the object is created.
    vector(unsigned len);

    // Copy constructor.
    vector(vector & src);

    // Destructor. This function is called when the object is destroyed.
    ~vector();

    // length accessor.
    unsigned len();

    // data accessor.
    double & operator[](unsigned i);

    // assignment operator.
    vector & operator=(vector & src);

    // Arithmetic operators...
    vector & operator+(vector & src);

    // Simple print function.
    void print();

  private:
    unsigned length;
    double * data;
    void check_index(unsigned i);
    void check_same_len(vector & src);
  };
}
#endif