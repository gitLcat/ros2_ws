cmake_minimum_required(VERSION 3.8)
project(scan_data)

#Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
add_executable(low_value src/array_data.cpp)
ament_target_dependencies(low_value rclcpp sensor_msgs)

install(TARGETS
  low_value
  DESTINATION lib/${PROJECT_NAME})

ament_package()
