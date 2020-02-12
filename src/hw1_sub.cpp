// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 01/29/20

#include <ros/ros.h>
#include <std_msgs/String.h>

void callback_receive_topic1data(const std_msgs::String& msg)
{ 
    ROS_INFO_STREAM("Message received: " << msg.data);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "hw1_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/hw1_topic_changed", 1000, 
                          callback_receive_topic1data);
    ros::spin();
}
