// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 01/29/20

#include <ros/ros.h>
#include <std_msgs/String.h>

int main (int argc, char **argv)
{
    ros::init(argc, argv, "news_pub2");
    ros::NodeHandle nh;
    std_msgs::String hw1_str1;
    hw1_str1.data = "MMMMMMM";

    ros::Publisher pub = nh.advertise<std_msgs::String>("/hw1_topic", 10);
    // 10: outgoing message queue size (required)
    double pub_freq = 1;
    nh.getParam("hw1_topic_pub_freq", pub_freq);
    ros::Rate rate(pub_freq);
    std_msgs::String hw1_str2;
    hw1_str2.data = "";
    nh.getParam("hw1_str2", hw1_str2.data);

    
    int i = 0;
    while (ros::ok()) {
        rate.sleep(); // sleep first not to loose the 1st message
        std_msgs::String msg;
        msg.data = hw1_str1.data + hw1_str2.data; // c++11
        pub.publish(msg); 
    }
}