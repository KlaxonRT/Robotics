// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 2/5/2020

#include <ros/ros.h>
#include <my_ros_msgs/MyStr.h>

int cmdNum = 0;

void callback_rcv_topic(const my_ros_msgs::MyStr& msg)
{
    ROS_INFO_STREAM("Msg received: " << msg.data << ", " << cmdNum);
    cmdNum++;
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "hw2str_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/hw2topic_str_changed", 1000,
        callback_rcv_topic);
    ros::spin();
}