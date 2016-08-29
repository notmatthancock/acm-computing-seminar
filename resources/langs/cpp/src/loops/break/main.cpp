#include <iostream>





int main() {
for(int i=0; i < 3; i++) {
  while(true) {
    std::cout << "Entering infinite loop number " << (i+1) << "\n";
    break;
  }
  std::cout << "We escaped the infinite loop!\n";
}
return 0;
}
