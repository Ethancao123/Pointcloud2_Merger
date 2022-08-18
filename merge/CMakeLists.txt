cmake_minimum_required(VERSION 3.0.2)
project(merge)
set(PCL_DIR "/usr/local/share/pcl-1.12/")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_filters
  sensor_msgs
  PCL
  tf2_ros
  geometry_msgs
  pcl_ros
  dynamic_reconfigure
  pcl_conversions
  roslint
)

catkin_package(
 INCLUDE_DIRS 
 LIBRARIES merge
 CATKIN_DEPENDS roscpp rospy std_msgs sensor_msgs
 DEPENDS system_lib PCL
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/lidarsync.cpp
# )

add_executable(merge_node src/lidarsync.cpp)
target_link_libraries(merge_node ${catkin_LIBRARIES})

add_executable(recorder_node src/compress.cpp)
target_link_libraries(recorder_node ${catkin_LIBRARIES})

add_executable(cloud_transformer src/cloud_transformer.cpp)
add_dependencies(cloud_transformer ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(cloud_transformer
  ${catkin_LIBRARIES}
)