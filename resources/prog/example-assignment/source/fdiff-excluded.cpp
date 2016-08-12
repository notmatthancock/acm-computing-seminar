#include "finite-differences.h"
#include "helpers.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

// Test function 1 and derivative.
double f1( double x) { return sin(x); }
double df1(double x) { return cos(x); }

// Test function 2 and derivative.
double f2( double x) { return    exp(-0.5*x*x); }
double df2(double x) { return -x*exp(-0.5*x*x); }

// Call signature: ./fdiff "forw|back|cent" "f1|f2" x
int main(int argc, char ** argv) {
    // Get argv's.
    std::string diff_type = argv[1];
    std::string func_type = argv[2];
    double x = std::stof(argv[3]);

    // Declarations.
    int m = 25; // num h vals to test
    double diff;
    double * h = helpers::logspace(-1, -5, m);
    double * a = new double [m];
    double * line; // store the slope and intercept for best fit line.

    std::ofstream fout;
    std::stringstream fname;

    // Loop through all `h` values.
    for(int i=0; i < m; i++) {
        if (func_type == "f1")
            diff = fdiff::central(f1, x, h[i]) - df1(x);
        else
            diff = fdiff::central(f2, x, h[i]) - df2(x);

        a[i] = std::abs(diff);
    }

    // Generate best-fit line parameters.
    line = helpers::fit_line_logspace(h, a, m);

    // Record best-fit line params.
    fname << "../data/" << diff_type
          << "-" << func_type
          << "-" << std::fixed << std::setprecision(1)
          <<  x << "-line-params-excluded.txt";
    fout.open(fname.str());
    fout << line[0] << " " << line[1];
    
    // Close line param file and delete param pointer data.
    fout.close();
    delete [] line;
    fname.str("");

    return 0;
}
