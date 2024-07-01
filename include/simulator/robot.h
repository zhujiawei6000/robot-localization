#pragma once
#include "simulator/measurement.h"
#include "simulator/utils.h"
#include "simulator/world.h"
#include <cmath>
#include <random>
#include <vector>
namespace pf {
class Robot {
public:
  Robot(float x, float y, float yaw, float forward_std, float turn_std,
        float measure_distance_std, float measure_angle_std)
      : x_{x}, y_{y}, yaw_{yaw}, forward_std_{forward_std}, turn_std_{turn_std},
        measure_distance_std_{measure_distance_std},
        measure_angle_std_{measure_angle_std} {}
  void Move(float desired_forward, float desired_rotation, World world) {
    float forward = GaussianNoisySample(desired_forward, forward_std_);
    float turn = GaussianNoisySample(desired_rotation, turn_std_);
    x_ = std::fmod(x_ + forward * std::cos(yaw_), world.BorderX());
    y_ = std::fmod(y_ + forward * std::sin(yaw_), world.BorderY());
    yaw_ = NormalizeAngle(yaw_ + turn);
  }

  std::vector<LandmarkLidarMeasurement> Measure(World world) {
    std::vector<LandmarkLidarMeasurement> measurements;
    measurements.reserve(world.Landmarks().size());
    for (auto &landmark : world.Landmarks()) {
      float dx = x_ - landmark.x;
      float dy = y_ - landmark.y;
      float distance =
          GaussianNoisySample(std::hypot(dx, dy), measure_distance_std_);
      float angle = GaussianNoisySample(std::atan2(dy, dx), measure_angle_std_);
      measurements.emplace_back(landmark.id, distance, angle);
    }
    return measurements;
  }

private:
  float GaussianNoisySample(float mean, float std) {
    std::random_device rnd{};
    std::mt19937 gen(rnd());
    std::normal_distribution<> d{mean, std};
    return d(gen);
  }
  float x_;
  float y_;
  float yaw_;
  float forward_std_;
  float turn_std_;
  float measure_distance_std_;
  float measure_angle_std_;
};

} // namespace pf