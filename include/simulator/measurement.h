#pragma once

namespace pf {
struct LandmarkLidarMeasurement {
  LandmarkLidarMeasurement(int i, float d, float a)
      : id{i}, distance{d}, angle{a} {}
  int id;
  float distance;
  float angle;
};

} // namespace pf