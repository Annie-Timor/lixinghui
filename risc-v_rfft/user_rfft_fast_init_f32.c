#include "user_rfft.h"

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_32)

/**
  @brief         Initialization function for the 32pt floating-point real FFT.
  @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
 */
riscv_status riscv_rfft_32_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 16U;
    S->fftLenRFFT = 32U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_16_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable16;
    Sint->pTwiddle = (float32_t *)twiddleCoef_16;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_32;

    return RISCV_MATH_SUCCESS;
}
#endif

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_64)

/**
  @brief         Initialization function for the 64pt floating-point real FFT.
  @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
 */
riscv_status riscv_rfft_64_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 32U;
    S->fftLenRFFT = 64U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_32_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable32;
    Sint->pTwiddle = (float32_t *)twiddleCoef_32;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_64;

    return RISCV_MATH_SUCCESS;
}
#endif

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_128)

/**
  @brief         Initialization function for the 128pt floating-point real FFT.
  @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
 */
riscv_status riscv_rfft_128_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 64U;
    S->fftLenRFFT = 128U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_64_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable64;
    Sint->pTwiddle = (float32_t *)twiddleCoef_64;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_128;

    return RISCV_MATH_SUCCESS;
}
#endif

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_256)

/**
  @brief         Initialization function for the 256pt floating-point real FFT.
  @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
*/
riscv_status riscv_rfft_256_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 128U;
    S->fftLenRFFT = 256U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_128_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable128;
    Sint->pTwiddle = (float32_t *)twiddleCoef_128;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_256;

    return RISCV_MATH_SUCCESS;
}
#endif

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_512)

/**
  @brief         Initialization function for the 512pt floating-point real FFT.
  @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
 */
riscv_status riscv_rfft_512_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 256U;
    S->fftLenRFFT = 512U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_256_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable256;
    Sint->pTwiddle = (float32_t *)twiddleCoef_256;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_512;

    return RISCV_MATH_SUCCESS;
}
#endif

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_1024)

/**
  @brief         Initialization function for the 1024pt floating-point real FFT.
  @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
 */
riscv_status riscv_rfft_1024_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 512U;
    S->fftLenRFFT = 1024U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_512_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable512;
    Sint->pTwiddle = (float32_t *)twiddleCoef_512;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_1024;

    return RISCV_MATH_SUCCESS;
}
#endif

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_2048)

/**
  @brief         Initialization function for the 2048pt floating-point real FFT.
  @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
 */
riscv_status riscv_rfft_2048_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 1024U;
    S->fftLenRFFT = 2048U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_1024_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable1024;
    Sint->pTwiddle = (float32_t *)twiddleCoef_1024;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_2048;

    return RISCV_MATH_SUCCESS;
}
#endif

#if defined(RISCV_ALL_FFT_TABLES) || defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_4096)

/**
* @brief         Initialization function for the 4096pt floating-point real FFT.
* @param[in,out] S  points to an riscv_rfft_fast_instance_f32 structure
  @return        execution status
                   - \ref RISCV_MATH_SUCCESS        : Operation successful
                   - \ref RISCV_MATH_ARGUMENT_ERROR : an error is detected
 */
riscv_status riscv_rfft_4096_fast_init_f32(riscv_rfft_fast_instance_f32 *S)
{

    riscv_cfft_instance_f32 *Sint;

    if (!S)
        return RISCV_MATH_ARGUMENT_ERROR;

    Sint = &(S->Sint);
    Sint->fftLen = 2048U;
    S->fftLenRFFT = 4096U;

    Sint->bitRevLength = RISCVBITREVINDEXTABLE_2048_TABLE_LENGTH;
    Sint->pBitRevTable = (uint16_t *)riscvBitRevIndexTable2048;
    Sint->pTwiddle = (float32_t *)twiddleCoef_2048;
    S->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_4096;

    return RISCV_MATH_SUCCESS;
}

#endif

riscv_status riscv_rfft_fast_init_f32(
    riscv_rfft_fast_instance_f32 *S,
    uint16_t fftLen)
{
    typedef riscv_status (*fft_init_ptr)(riscv_rfft_fast_instance_f32 *);
    fft_init_ptr fptr = 0x0;

    switch (fftLen)
    {
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_2048) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_4096))
    case 4096U:
        fptr = riscv_rfft_4096_fast_init_f32;
        break;
#endif
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_1024) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_2048))
    case 2048U:
        fptr = riscv_rfft_2048_fast_init_f32;
        break;
#endif
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_512) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_1024))
    case 1024U:
        fptr = riscv_rfft_1024_fast_init_f32;
        break;
#endif
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_256) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_512))
    case 512U:
        fptr = riscv_rfft_512_fast_init_f32;
        break;
#endif
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_128) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_256))
    case 256U:
        fptr = riscv_rfft_256_fast_init_f32;
        break;
#endif
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_64) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_128))
    case 128U:
        fptr = riscv_rfft_128_fast_init_f32;
        break;
#endif
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_32) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_64))
    case 64U:
        fptr = riscv_rfft_64_fast_init_f32;
        break;
#endif
#if defined(RISCV_ALL_FFT_TABLES) || (defined(RISCV_TABLE_TWIDDLECOEF_F32_16) && defined(RISCV_TABLE_TWIDDLECOEF_RFFT_F32_32))
    case 32U:
        fptr = riscv_rfft_32_fast_init_f32;
        break;
#endif
    default:
        return RISCV_MATH_ARGUMENT_ERROR;
    }

    if (!fptr)
        return RISCV_MATH_ARGUMENT_ERROR;
    return fptr(S);
}