// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own.
// Name: Austin Placinto
// Date: 01/29/20

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

ros::Publisher pub;

void callback_change_topicdata(const std_msgs::String& msg)
{ 
    int index = rand() % msg.data.length() + 1;
    std::string temp = msg.data;
    temp.replace(index, 1, " ");
    std_msgs::String changed_msg;
    changed_msg.data = temp;
    pub.publish(changed_msg);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "hw1_changer");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/hw1_topic", 1000, 
        callback_change_topicdata);
    pub = nh.advertise<std_msgs::String>("/hw1_topic_changed", 10);
    // 10: outgoing message queue size (required)
    ros::spin();
}