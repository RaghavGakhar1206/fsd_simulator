#include <ros/ros.h>
#include <iostream>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/PointCloud2.h>

ros::NodeHandle n;
void callback1(const nav_msgs::Odometry data)
{
    ros::Publisher pub = n.advertise<nav_msgs::Odometry>("odom", 100);
    pub = data;

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "conversions");
    ros::Subscriber sub1 = n.subscribe<nav_msgs::Odometry>("robot_control/odom", 100, callback1);
}