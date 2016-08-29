#include <iostream>
#include "my_library.h"

int main() {
    double * xs = my_namespace::linspace(-1,1,5);
    my_namespace::print_array(xs, 5);
    delete [] xs;

    return 0;
}
