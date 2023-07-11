
#ifndef _FFT_H
#define _FFT_H

#define PI 3.14159265358979
#define pi 3.14159265358979

typedef struct
{
    float real;
    float imag;
} Complex;

enum
{
    FFT,
    IFFT
};

int fft(Complex *x, int N);
int ifft(Complex *x, int N);

#endif // _FFT_H
