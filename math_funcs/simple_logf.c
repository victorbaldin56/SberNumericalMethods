#include "simple_logf.h"

#include <errno.h>
#include <math.h>

float simple_logf(float x) {
  if (x <= 0) {
    errno = ERANGE;
    return NAN;
  }
}
