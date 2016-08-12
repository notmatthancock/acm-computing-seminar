#ifndef HELPERS_H
#define HELPERS_H

#include <cmath>
#include <iostream>

namespace helpers {
    // Generate an array of `n_points` equally-spaced
    // points after log-transformation, starting from `10^pow_start`
    // until `10^pow_stop`.
    double * logspace(int pow_start, int pow_stop, int n_points) {
        double * arr = new double [n_points];
        double step = (pow_stop-pow_start) / (n_points-1.0);

        for(int i=0; i < n_points; i++) {
            arr[i] = pow(10, pow_start + i*step);
        }

        return arr;
    }

    
    // Determine the optimal slope and intercept in log-transformed
    // version of `h` and `a`.
    //
    // `h` is the array of h values used.
    // `a` is the array of absolute errors.
    //
    // returns: line
    // line[0] is the intercept.
    // line[1] is the slope.
    double * fit_line_logspace(double * h, double * a, int n_points) {
        double u, v;

        double usum = 0.0; double usqr = 0.0;
        double vsum = 0.0; double uvin = 0.0;

        for(int i=0; i < n_points; i++) {
            u = log10(h[i]);
            v = log10(a[i]);

            usum += u;
            usqr += u*u;
            vsum += v;
            uvin += u*v;
        }

        double denom = n_points*usqr - usum*usum;
        double b = usqr*vsum - usum*uvin;
        double p = n_points*uvin - usum*vsum;
        b /= denom; p /= denom;

        double * line = new double [2];
        line[0] = b; // intercept
        line[1] = p; // slope

        return line;
    }
}

#endif
