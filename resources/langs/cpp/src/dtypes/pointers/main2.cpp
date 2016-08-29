#include <iostream>





int main() {
double * a;
double b = 7.3;
double c;

// Now `a` holds the memory address of `b`.
a = &b;

// `*a` obtains the value of the variable
// at the memory address held by `a`.
// So, `c` is 7.3.
c = *a;

std::cout << c << "\n";
return 0;
}
