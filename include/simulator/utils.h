#include <cmath>
namespace pf {
double NormalizeAngle(double x) {
  x = fmod(x, 360);
  if (x < 0)
    x += 360;
  return x;
}
} // namespace kf