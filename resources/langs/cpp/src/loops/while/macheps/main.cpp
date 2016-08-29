#include <iostream>
#include <limits>





int main() {
double eps = 1;
int count = 1;

while(1.0 + eps*0.5 > 1.0) {
    eps *= 0.5;
    count += 1;
}

std::cout << eps << ", " << std::numeric_limits<double>::epsilon() << "\n"
          << count << ", " << std::numeric_limits<double>::digits;
return 0;
}
