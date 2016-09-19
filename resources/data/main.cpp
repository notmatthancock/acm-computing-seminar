#include <iostream>
#include <fstream>

int main() {

    std::fstream xin("./x.txt", std::ios_base::in);
    std::fstream yin("./y.txt", std::ios_base::in);

    double x[101];
    double y[101];
    int i = 0;
    double integral;

    for(int i=0; i < 101; i++) {
        xin >> x[i];
        yin >> y[i];
    }

    xin.close(); yin.close();

    for(int i=0; i < 100; i++) {
        integral += 0.5*(x[i+1]-x[i])*(y[i]+y[i+1]);
    }

    std::cout << integral << "\n";


    return 0;
}
