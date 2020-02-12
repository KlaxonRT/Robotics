#include <ros/ros.h>
int main (int argc, char **argv)
{
    ros::init(argc, argv, "hellos_cpp_node"); // unique node name!
    ros::NodeHandle nh;
    ROS_INFO("hellos_cpp_node has been started");

    ros::Rate rate(2); // 2 per second

    while (ros::ok())
    {
        ROS_INFO("Hello!!");
        rate.sleep();
    }
}