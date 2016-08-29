#include <iostream>





int main() {
double * a;
double b = 7;

// This obtains the memory address of `b`.
a = &b;

// Prints some memory address (starts with 0x)
std::cout << a << std::endl;
return 0;
}
