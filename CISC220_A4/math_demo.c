// math_demo.c
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const double PI = 3.1415926535897931;

void normpdf(double x, double *pdf) {
    *pdf = (1 / (sqrt(2 * PI))) * exp(-(x*x)/2);
}

void fmtstr(unsigned int width, unsigned int precision, char s[]) {
    unsigned int i = 0;
    s[i++] = '%';         // fills in s[0] and sets i to 1 so that you can
                          // fill in the next element of s
    // ...
    if (width > 9) {
        s[i++] = '0' + (width / 10);
        s[i++] = '0' + (width % 10);
    } else {
        s[i++] = '0' + (width % 10);
    }
    s[i++] = '.';
    if (precision > 9) {
        s[i++] = '0' + (precision / 10);
        s[i++] = '0' + (precision % 10);
    } else {
        s[i++] = '0' + (precision);
    }
    s[i++] = 'f';
    s[i++] = '\0';
}


int main(int argc, char *argv[]) {
    if (argc == 2) {
        double val = atof(argv[1]);
        double pdf;
        normpdf(val, &pdf);
        char fstr[8];
        for (int i = 0; i <= 15; i++) {
            fmtstr(20, i, fstr);
            printf(fstr, pdf);
            printf("\n");
        }
    } else {
        fprintf(stderr, "Usage: math_demo num1 [num2]\n");
        exit(1);
    }
    return 0;
}