#include "fft.h"
#include "user_rfft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define FFT_LEN 64

void user_fft_data_init(float32_t *data, int len);
void user_fft_data_init_complex(Complex *data, int len);

int main(int argc, char **argv)
{
    riscv_rfft_fast_instance_f32 S = {0};
    float32_t rfft_in[FFT_LEN] = {0};
    float32_t rfft_out[FFT_LEN] = {0};
    Complex cfft_in[FFT_LEN] = {0};

    FILE *fp = NULL;
    FILE *fp_c = NULL;

    fp = fopen("data.txt", "w");
    fp_c = fopen("data2.txt", "w");

    riscv_rfft_fast_init_f32(&S, FFT_LEN);
    user_fft_data_init(rfft_in, FFT_LEN);
    user_fft_data_init_complex(cfft_in, FFT_LEN);

    fprintf(fp, "data in:\n");
    fprintf(fp_c, "data in:\n");
    // for (int i = 0; i < FFT_LEN; i += 2)
    // {
    //     fprintf(fp, "%12.4f,%12.4f\n", rfft_in[i], rfft_in[i + 1]);
    //     fprintf(fp_c, "%12.4f,%12.4f\n", cfft_in[i].real, cfft_in[i + 1].real);
    // }

    riscv_rfft_fast_f32(&S, rfft_in, rfft_out, 0);
    fft(cfft_in, FFT_LEN);

    printf("111\n");

    fprintf(fp, "fft out:\n");
    fprintf(fp_c, "fft out:\n");
    for (int i = 0; i < FFT_LEN; i += 2)
    {
        fprintf(fp, "%12.4f,%12.4f\n", rfft_out[i], rfft_out[i + 1]);
    }
    for (int i = 0; i < FFT_LEN / 2 + 1; i++)
    {
        fprintf(fp_c, "%12.4f,%12.4f\n", cfft_in[i].real, cfft_in[i].imag);
    }

    riscv_rfft_fast_f32(&S, rfft_out, rfft_in, 1);
    ifft(cfft_in, FFT_LEN);

    fprintf(fp, "ifft out:\n");
    fprintf(fp_c, "ifft out:\n");
    for (int i = 0; i < FFT_LEN; i += 2)
    {
        fprintf(fp, "%12.4f,%12.4f\n", rfft_in[i], rfft_in[i + 1]);
        fprintf(fp_c, "%12.4f,%12.4f\n", cfft_in[i].real, cfft_in[i + 1].real);
    }
    fprintf(fp, "\ndone\n");
    fprintf(fp_c, "\ndone\n");

    fclose(fp_c);
    fclose(fp);
}

void user_fft_data_init(float32_t *data, int len)
{
    for (int i = 0; i < len; i++)
    {
        data[i] = sin(2 * M_PI * 10 * i / 100);
    }
}

void user_fft_data_init_complex(Complex *data, int len)
{
    for (int i = 0; i < len; i++)
    {
        data[i].real = sin(2 * M_PI * 10 * i / 100);
        data[i].imag = 0;
    }
}