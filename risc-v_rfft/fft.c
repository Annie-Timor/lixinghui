#include "fft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * FFT Algorithm
 * === Inputs ===
 * x : complex numbers
 * N : nodes of FFT. for example:64,128,256,512,1024,etc.
 * === Output ===
 * the @x contains the result of FFT algorithm, so the original data
 * in @x is destroyed, please store them before using FFT.
 */

int fft(Complex *x, int N)
{
    int i, j, l, k, ip;
    static int M = 0;
    static int le, le2;
    static float sR, sI, tR, tI, uR, uI;

    M = (int)(log(N) / log(2));

    /*
     * bit reversal sorting
     */
    l = N / 2;
    j = l;
    // BitReverse(x,x,N,M);
    for (i = 1; i <= N - 2; i++)
    {
        if (i < j)
        {
            tR = x[j].real;
            tI = x[j].imag;
            x[j].real = x[i].real;
            x[j].imag = x[i].imag;
            x[i].real = tR;
            x[i].imag = tI;
        }
        k = l;
        while (k <= j)
        {
            j = j - k;
            k = k / 2;
        }
        j = j + k;
    }

    /*
     * For Loops
     */
    for (l = 1; l <= M; l++)
    { /* loop for ceil{log2(N)} */
        le = (int)pow(2, l);
        le2 = (int)(le / 2);
        uR = 1;
        uI = 0;
        sR = cos(PI / le2);
        sI = -sin(PI / le2);
        for (j = 1; j <= le2; j++)
        { /* loop for each sub DFT */
            // jm1 = j - 1;
            for (i = j - 1; i <= N - 1; i += le)
            { /* loop for each butterfly */
                ip = i + le2;
                tR = x[ip].real * uR - x[ip].imag * uI;
                tI = x[ip].real * uI + x[ip].imag * uR;
                x[ip].real = x[i].real - tR;
                x[ip].imag = x[i].imag - tI;
                x[i].real += tR;
                x[i].imag += tI;
            } /* Next i */
            tR = uR;
            uR = tR * sR - uI * sI;
            uI = tR * sI + uI * sR;
        } /* Next j */
    }     /* Next l */

    return 0;
}

/*
 * Inverse FFT Algorithm
 * === Inputs ===
 * x : complex numbers
 * N : nodes of FFT. @N should be power of 2, that is 2^(*)
 * === Output ===
 * the @x contains the result of FFT algorithm, so the original data
 * in @x is destroyed, please store them before using FFT.
 */
int ifft(Complex *x, int N)
{
    int k = 0;

    for (k = 0; k <= N - 1; k++)
    {
        x[k].imag = -x[k].imag;
    }

    fft(x, N); /* using FFT */

    for (k = 0; k <= N - 1; k++)
    {
        x[k].real = x[k].real / N;
        x[k].imag = -x[k].imag / N;
    }

    return 0;
}
