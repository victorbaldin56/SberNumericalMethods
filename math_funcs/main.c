#include <stdio.h>
#include <stdlib.h>

#include "snm_logf.h"

int main() {
  float x;
  if (scanf("%f", &x) != 1) {
    fprintf(stderr, "Could not read float from stdin\n");
    return EXIT_FAILURE;
  }
  printf("%f\n", snm_logf(x));
  return 0;
}
