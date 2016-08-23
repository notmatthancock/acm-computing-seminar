#include <iostream>
#include "vector.h"

int main() {
    vec::vector v(5);

    std::cout << "`v` has length = " << v.len() << "\n";

    v.element(0) = -1.27;
    v.element(3) = 3.1;

    v.print();

    v.element(5) = 1234.0;

    return 0;
}
