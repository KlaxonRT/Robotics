// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 2/5/2020

#include <ros/ros.h>
#include <my_ros_msgs/MyStr.h>
#include <string>

const std::string localString = "AustinPlacinto";

int main (int argc, char **argv) {
    ros::init(argc, argv, "hw2str_pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<my_ros_msgs::MyStr>(
        "/hw2_topic", 10);

    double pub_freq = 1; // default is 1 Hz
    nh.getParam("/hw2_pub_freq", pub_freq);
    ros::Rate rate(pub_freq);

    while(ros::ok()) {
        my_ros_msgs::MyStr msg;
        msg.data = localString;
        msg.command = rand()%3;
        pub.publish(msg);
        rate.sleep();
    }
}