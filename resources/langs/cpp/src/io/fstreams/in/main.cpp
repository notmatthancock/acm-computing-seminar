#include <iostream>
#include <fstream>

int main() {
    std::fstream fin("./data/vector.txt", std::ios_base::in);
    double vector[6];
    int i = 0;
    while(fin >> vector[i]) {
      std::cout << vector[i] << " ";
      i++;
    }
    return 0;
}
