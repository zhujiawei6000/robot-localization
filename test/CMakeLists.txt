cmake_minimum_required(VERSION 3.15)
enable_testing()

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
find_package(GTest REQUIRED)
add_executable(
  robot_test
  ${sources}
)
target_link_libraries(
    robot_test PUBLIC
    RobotLocalization
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(robot_test)