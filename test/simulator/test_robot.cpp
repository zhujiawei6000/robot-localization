#include "simulator/robot.h"
#include "simulator/world.h"
#include <gtest/gtest.h>
// Demonstrate some basic assertions.
TEST(RobotTest, BasicAssertions) {
  // Expect two strings not to be equal.
  pf::Robot robot{1, 2, M_PI, 0.1, 0.1, 0.1, 0.1};
  pf::World world{1, 2};
  robot.Move(2, M_PI, world);
  auto measurement = robot.Measure(world);
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}