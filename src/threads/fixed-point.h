#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

typedef int32_t fp_t;

#define F (1 << 14)

/** Conversion functions. */
#define INT_TO_FP(n) ((n) * F)
#define FP_TO_INT_TRUNC(x) ((x) / F)
#define FP_TO_INT_NEAR(x) ((x) >= 0 ? ((x) + F / 2) / F : ((x) - F / 2) / F)

/** Addition and subtraction. */
#define ADD_FP(x, y) ((x) + (y))
#define ADD_FP_INT(x, n) ((x) + (n) * F)
#define SUB_FP(x, y) ((x) - (y))
#define SUB_FP_INT(x, n) ((x) - (n) * F)
#define SUB_INT_FP(n, x) ((n) * F - (x))

/** Multiplication and division. */
#define MUL_FP(x, y) ((((int64_t)(x)) * (y)) / F)
#define MUL_FP_INT(x, n) ((x) * (n))
#define DIV_FP(x, y) ((((int64_t)(x)) * F) / (y))
#define DIV_FP_INT(x, n) ((x) / (n))

#endif