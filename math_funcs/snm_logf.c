/**
 * Single precision logf(x) function.
 *
 * Low accuracy (<3.5 ulp) logarithm function algorithm. Uses TO_NEAREST
 * rounding mode.
 *
 * Step 1 - Argument check:
 *   Filter out negative x values.
 *
 * Step 2 - Range reduction:
 *   x = x_0 * 2^n
 */

#include "snm_logf.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

/**
 * IEEE754 single point precision format.
 */
enum FpLayout {
  kFpLayoutMantissaWidth = 23,
};

/**
 * Masks to extract floating point layout components (mantissa, exponent, sign).
 */
enum FpMask {
  kFpMaskMantissa = 0xffffff,
  kFpMaskExp = 0xff << kFpLayoutMantissaWidth,
};

static inline uint32_t castToBits(float x) {
  uint32_t fpbits;
  memcpy(&fpbits, &x, 4);  // complies strict aliasing requirements
  return fpbits;
}

static inline uint32_t getMantissa(uint32_t bits) {
  return bits & kFpMaskMantissa;
}

static inline uint32_t getExp(uint32_t bits) {
  return (bits & kFpMaskExp) >> kFpLayoutMantissaWidth;
}

float snm_logf(float x) {
  if (x <= 0) {
    errno = EDOM;
    return NAN;
  }

  uint32_t bits = castToBits(x);
  uint32_t x_0 = getMantissa(x);
  uint32_t exp = getExp(bits);
  return 0;
}
