#include <stdio.h>

#include "monte_carlo_pi/monte_carlo_pi.h"

#define NUM_POINTS 100000000

int main() {
  mcpi_monteCarloPi(NUM_POINTS);
  return 0;
}
