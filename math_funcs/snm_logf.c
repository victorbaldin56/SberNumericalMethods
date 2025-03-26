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
 *
 * Step 3 - Second range reduction using table lookup:
 *   ln(x) = ln(2^n * x_0) = n * ln(2) + T_i + poly(r)
 *
 * Step 4 - Taylor series approximation:
 */

#include "snm_logf.h"

#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

/**
 * IEEE754 single point precision format.
 */
enum FpLayout {
  kFpLayoutSigWidth = 23,
};

/**
 * Masks to extract floating point layout components (mantissa, exponent, sign).
 */
enum FpMask {
  kFpMaskSig = 0xffffff,
  kFpMaskExp = 0xff << kFpLayoutSigWidth,
};

static inline uint32_t castToBits(float x) {
  uint32_t fpbits;
  memcpy(&fpbits, &x, 4);  // complies strict aliasing requirements
  return fpbits;
}

static inline uint32_t getSignificant(uint32_t bits) {
  return bits & kFpMaskSig;
}

static inline uint32_t getExp(uint32_t bits) {
  return (bits & kFpMaskExp) >> kFpLayoutSigWidth;
}

static inline float taylorEval(float r) {
  assert(r < 0x0.1p1);
  float r2 = r * r;
  float r3 = r2 * r;
  return r + 0.25 * r2 + 0.1666667 * r3;
}

float snm_logf(float x) {
  if (x <= 0) {
    errno = EDOM;
    return NAN;
  }

  uint32_t bits = castToBits(x);
  uint32_t x_0 = getSignificant(x);
  uint32_t exp = getExp(bits);
  return 0;
}
