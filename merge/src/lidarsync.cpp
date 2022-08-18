#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>

using namespace sensor_msgs;

int num_lidars = 10;

sensor_msgs::PointCloud2* points = new sensor_msgs::PointCloud2[10];
ros::Publisher pub;

sensor_msgs::PointCloud2 merge() {
  sensor_msgs::PointCloud2 returned = points[0];
  for(int i = 1; i < num_lidars; i++)
  {
    pcl::concatenatePointCloud(returned, points[i], returned);
  }
  ROS_INFO("merging clouds");
  return returned;
}

void callback0(const sensor_msgs::PointCloud2 data) {
  points[0] = data;
}

void callback1(const sensor_msgs::PointCloud2 data) {
  points[1] = data;
}

void callback2(const sensor_msgs::PointCloud2 data) {
  points[2] = data;
}

void callback3(const sensor_msgs::PointCloud2 data) {
  points[3] = data;
}

void callback4(const sensor_msgs::PointCloud2 data) {
  points[4] = data;
}

void callback5(const sensor_msgs::PointCloud2 data) {
  points[5] = data;
}

void callback6(const sensor_msgs::PointCloud2 data) {
  points[6] = data;
}

void callback7(const sensor_msgs::PointCloud2 data) {
  points[7] = data;
}

void callback8(const sensor_msgs::PointCloud2 data) {
  points[8] = data;
}

void callback9(const sensor_msgs::PointCloud2 data) {
  points[9] = data;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "merge_node");
  ros::NodeHandle nh;
  pub = nh.advertise<pcl::PointCloud<pcl::PointXYZ>>("merged_cloud", 5);
  ros::Rate rate(10);
  ros::Subscriber sub0 = nh.subscribe("ivu_aligned0", 1, callback0);
  ros::Subscriber sub1 = nh.subscribe("ivu_aligned1", 1, callback1);
  ros::Subscriber sub2 = nh.subscribe("ivu_aligned2", 1, callback2);
  ros::Subscriber sub3 = nh.subscribe("ivu_aligned3", 1, callback3);
  ros::Subscriber sub4 = nh.subscribe("ivu_aligned4", 1, callback4);
  ros::Subscriber sub5 = nh.subscribe("ivu_aligned5", 1, callback5);
  ros::Subscriber sub6 = nh.subscribe("ivu_aligned6", 1, callback6);
  ros::Subscriber sub7 = nh.subscribe("ivu_aligned7", 1, callback7);
  ros::Subscriber sub8 = nh.subscribe("ivu_aligned8", 1, callback8);
  ros::Subscriber sub9 = nh.subscribe("ivu_aligned9", 1, callback9);
  ROS_INFO("started merge_node");
  while (ros::ok()) {
    pub.publish(merge());
    ros::spinOnce();
    rate.sleep();
  }
  return 0;
}