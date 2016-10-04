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
    unsigned len() const;

    // data accessor.
    double & operator[](unsigned i) const;

    // assignment operator.
    vector & operator=(const vector & src);

    // Simple print function.
    void print() const;

  private:
    unsigned length;
    double * data;
    void check_index(unsigned i) const;
  };
}
#endif
