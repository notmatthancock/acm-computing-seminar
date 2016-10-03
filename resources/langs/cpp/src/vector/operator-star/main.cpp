#include <iostream>
#include "vector.h"

int main() {
    vec::vector v(5);

    v[0] = -1.27;
    v[3] = 3.1;

    vec::vector w = 2*v;

    w.print();

    std::cout << "\n";

    w = w*0.5;

    w.print();

    return 0;
}
