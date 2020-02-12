#include <ros/ros.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "hello_cpp_node");
    ros::NodeHandle nh;
    ROS_INFO("hello_cpp_node has been started");
    ros::Duration(2.0).sleep(); // seconds
    ROS_INFO("Exit");
}