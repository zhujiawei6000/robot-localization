#pragma once
#include <vector>

namespace pf {
struct Landmark {
  int id;
  float x;
  float y;
};
struct World {
  float BorderY() const { return max_y_;}
  float BorderX() const { return max_x_;}
  std::vector<Landmark> Landmarks() const { return landmarks_;}
private:
  float max_y_;
  float max_x_;
  std::vector<Landmark> landmarks_;
};
} // namespace