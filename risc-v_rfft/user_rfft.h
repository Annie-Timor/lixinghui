#ifndef USER_MATH_H
#define USER_MATH_H

#include <stdint.h>

typedef float float32_t;
typedef double float64_t;

// #define RISCV_ALL_FFT_TABLES
// #define USER_RFFT_32
#define USER_RFFT_64
// #define USER_RFFT_128
// #define USER_RFFT_256
// #define USER_RFFT_512
// #define USER_RFFT_1024
// #define USER_RFFT_2048
// #define USER_RFFT_4096

/*

*/
#ifdef USER_RFFT_32
#define RISCV_TABLE_TWIDDLECOEF_F32_16
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_32
#define RISCV_TABLE_BITREVIDX_FLT_16
#define RISCVBITREVINDEXTABLE_16_TABLE_LENGTH ((uint16_t)20)
extern const uint16_t riscvBitRevIndexTable16[RISCVBITREVINDEXTABLE_16_TABLE_LENGTH];
extern const float32_t twiddleCoef_16[32];
extern const float32_t twiddleCoef_rfft_32[32];
#endif
/*
 */
#ifdef USER_RFFT_64
#define RISCV_TABLE_TWIDDLECOEF_F32_32
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_64
#define RISCV_TABLE_BITREVIDX_FLT_32
#define RISCVBITREVINDEXTABLE_32_TABLE_LENGTH ((uint16_t)48)
extern const uint16_t riscvBitRevIndexTable32[RISCVBITREVINDEXTABLE_32_TABLE_LENGTH];
extern const float32_t twiddleCoef_32[64];
extern const float32_t twiddleCoef_rfft_64[64];
#endif
/*
 */
#ifdef USER_RFFT_128
#define RISCV_TABLE_TWIDDLECOEF_F32_64
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_128
#define RISCV_TABLE_BITREVIDX_FLT_64
#define RISCVBITREVINDEXTABLE_64_TABLE_LENGTH ((uint16_t)56)
extern const uint16_t riscvBitRevIndexTable64[RISCVBITREVINDEXTABLE_64_TABLE_LENGTH];
extern const float32_t twiddleCoef_64[128];
extern const float32_t twiddleCoef_rfft_128[128];
#endif
/*
 */
#ifdef USER_RFFT_256
#define RISCV_TABLE_TWIDDLECOEF_F32_128
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_256
#define RISCV_TABLE_BITREVIDX_FLT_128
#define RISCVBITREVINDEXTABLE_128_TABLE_LENGTH ((uint16_t)208)
extern const uint16_t riscvBitRevIndexTable128[RISCVBITREVINDEXTABLE_128_TABLE_LENGTH];
extern const float32_t twiddleCoef_128[256];
extern const float32_t twiddleCoef_rfft_256[256];
#endif

/*
 */
#ifdef USER_RFFT_512
#define RISCV_TABLE_TWIDDLECOEF_F32_256
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_512
#define RISCV_TABLE_BITREVIDX_FLT_256
#define RISCVBITREVINDEXTABLE_256_TABLE_LENGTH ((uint16_t)440)
extern const uint16_t riscvBitRevIndexTable256[RISCVBITREVINDEXTABLE_256_TABLE_LENGTH];
extern const float32_t twiddleCoef_256[512];
extern const float32_t twiddleCoef_rfft_512[512];
#endif

/*
 */
#ifdef USER_RFFT_1024
#define RISCV_TABLE_TWIDDLECOEF_F32_512
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_1024
#define RISCV_TABLE_BITREVIDX_FLT_512
#define RISCVBITREVINDEXTABLE_512_TABLE_LENGTH ((uint16_t)448)
extern const uint16_t riscvBitRevIndexTable512[RISCVBITREVINDEXTABLE_512_TABLE_LENGTH];
extern const float32_t twiddleCoef_512[1024];
extern const float32_t twiddleCoef_rfft_1024[1024];
#endif

/*
 */
#ifdef USER_RFFT_2048
#define RISCV_TABLE_TWIDDLECOEF_F32_1024
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_2048
#define RISCV_TABLE_BITREVIDX_FLT_1024
#define RISCVBITREVINDEXTABLE_1024_TABLE_LENGTH ((uint16_t)1800)
extern const uint16_t riscvBitRevIndexTable1024[RISCVBITREVINDEXTABLE_1024_TABLE_LENGTH];
extern const float32_t twiddleCoef_1024[2048];
extern const float32_t twiddleCoef_rfft_2048[2048];
#endif

#ifdef USER_RFFT_4096
#define RISCV_TABLE_TWIDDLECOEF_F32_2048
#define RISCV_TABLE_TWIDDLECOEF_RFFT_F32_4096
#define RISCV_TABLE_BITREVIDX_FLT_2048
#define RISCVBITREVINDEXTABLE_2048_TABLE_LENGTH ((uint16_t)3808)
extern const uint16_t riscvBitRevIndexTable2048[RISCVBITREVINDEXTABLE_2048_TABLE_LENGTH];
extern const float32_t twiddleCoef_2048[4096];
extern const float32_t twiddleCoef_rfft_4096[4096];
#endif

// #define RISCV_TABLE_BITREVIDX_FLT_4096
// #define RISCV_TABLE_TWIDDLECOEF_F32_4096
// #define RISCVBITREVINDEXTABLE_4096_TABLE_LENGTH ((uint16_t)4032)
// extern const uint16_t riscvBitRevIndexTable4096[RISCVBITREVINDEXTABLE_4096_TABLE_LENGTH];
// extern const float32_t twiddleCoef_4096[8192];

typedef enum
{
    RISCV_MATH_SUCCESS = 0,         /**< No error */
    RISCV_MATH_ARGUMENT_ERROR = -1, /**< One or more arguments are incorrect */
    RISCV_MATH_LENGTH_ERROR = -2,   /**< Length of data buffer is incorrect */
    RISCV_MATH_SIZE_MISMATCH = -3,  /**< Size of matrices is not compatible with the operation */
    RISCV_MATH_NANINF = -4,         /**< Not-a-number (NaN) or infinity is generated */
    RISCV_MATH_SINGULAR = -5,       /**< Input matrix is singular and cannot be inverted */
    RISCV_MATH_TEST_FAILURE = -6    /**< Test Failed */
} riscv_status;

/**
 * @brief Instance structure for the floating-point CFFT/CIFFT function.
 */
typedef struct
{
    uint16_t fftLen;              /**< length of the FFT. */
    const float32_t *pTwiddle;    /**< points to the Twiddle factor table. */
    const uint16_t *pBitRevTable; /**< points to the bit reversal table. */
    uint16_t bitRevLength;        /**< bit reversal table length. */
} riscv_cfft_instance_f32;

/**
 * @brief Instance structure for the floating-point RFFT/RIFFT function.
 */
typedef struct
{
    riscv_cfft_instance_f32 Sint;  /**< Internal CFFT structure. */
    uint16_t fftLenRFFT;           /**< length of the real sequence */
    const float32_t *pTwiddleRFFT; /**< Twiddle factors real stage  */
} riscv_rfft_fast_instance_f32;

/*
 * function extern
 *
 */

riscv_status riscv_rfft_fast_init_f32(
    riscv_rfft_fast_instance_f32 *S,
    uint16_t fftLen);

void riscv_rfft_fast_f32(
    riscv_rfft_fast_instance_f32 *S,
    float32_t *p, float32_t *pOut,
    uint8_t ifftFlag);

#endif // !USER_MATH_H
