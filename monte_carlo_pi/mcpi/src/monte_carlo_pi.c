#include "monte_carlo_pi/monte_carlo_pi.h"

#include <stdbool.h>

static Point2 createRandomPoint2(double min_x, double max_x,
                                 double min_y, double max_y);
static bool isPointInsideCircle(const Point2* point, const Circle2* circle);

double mcpi_monteCarloPi(size_t num_points) {
  Circle2 circle = {.center = {0.0, 0.0}, .radius = 1.0};
  size_t count_inner = 0;
  for (size_t n = 0; n < num_points; ++n) {
    Point2 point = createRandomPoint2(-1.0, 1.0, -1.0, 1.0);
    if (isPointInsideCircle(&point, &circle)) {
      ++count_inner;
    }
  }
}
