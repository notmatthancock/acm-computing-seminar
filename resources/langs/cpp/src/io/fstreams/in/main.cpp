#include <iostream>
#include <fstream>

int main() {
    std::fstream fin("./data/vector.txt", std::ios_base::in);
    double vector[6];
    double num;
    int i = 0;
    //while(fin >> vector[i]) {
    while(fin >> num) {
      //std::cout << vector[i] << " ";
      std::cout << num << "\n";
      i++;
    }
    return 0;
}
