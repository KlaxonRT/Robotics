// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 2/5/2020

#include <ros/ros.h>
#include <my_ros_msgs/MyStr.h>
#include <string>

ros::Publisher pub;

void callback_change_topicdata(const my_ros_msgs::MyStr& msg)
{ 
    my_ros_msgs::MyStr changed_msg;
    switch(msg.command)
    {
        case 1:
            {
                std::string upper = "";
                for(int i = 0; i < msg.data.length(); i++)
                    upper += toupper(msg.data[i]);
                changed_msg.data = upper;
                break;
            }
        case 2:
            {
                std::string reverse = "";
                for(int i = msg.data.length() - 1; i > -1; i--)
                    reverse += msg.data[i];
                changed_msg.data = reverse;
                break;
            }
        default:
            {
                changed_msg.data = msg.data;
                break;
            }
    }
    pub.publish(changed_msg);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "hw2str_changer");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/hw2_topic", 1000, 
        callback_change_topicdata);
    pub = nh.advertise<my_ros_msgs::MyStr>("/hw2topic_str_changed", 10);
    // 10: outgoing message queue size (required)
    ros::spin();
}