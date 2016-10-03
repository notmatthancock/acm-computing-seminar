#include <iostream>
#include "vector.h"

int main() {
    vec::vector v(5);

    v[0] = -1.27;
    v[3] = 3.1;

    vec::vector w = v;

    vec::vector z = w+v;
    z.print();

    vec::vector q(6);
    q+v;

    return 0;
}
