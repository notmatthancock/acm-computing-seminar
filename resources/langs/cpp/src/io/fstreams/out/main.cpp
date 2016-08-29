#include <fstream>
#include <cmath>

int main() {
  std::fstream fout("./data/new_shiny_data.txt", std::ios_base::out);
  double x;

  fout << "x\tsin(x)\n";

  for(int i=0; i < 11; i++) {
    x = i / 10.0;
    fout << x << "\t" << sin(x) << "\n";
  }

  fout.close();

  return 0;
}
