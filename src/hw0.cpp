// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own.
// Name: Austin Placinto
// Date: 1/21/2020

#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "hw0string_node"); // do not need to match with CMakeLists.text node
    ros::NodeHandle nh;
    ROS_INFO("hw0string_node has been started");
    std_msgs::String msg;
    msg.data = "Hello World from a node by AP";
    ROS_INFO_STREAM("My message is: " << msg.data);
    ROS_INFO_STREAM("The length of my message is: " << msg.data.length()); // long unsigned
    ROS_INFO_STREAM("The 3rd char in my message is: " << msg.data[2]);
    ROS_INFO_STREAM("The last char in my message is: " << msg.data[msg.data.length()-1]);

    // Convert the string msg to upper case
    std::string upper = "";
    for(int i = 0; i < msg.data.length(); i++)
        upper += toupper(msg.data[i]);
    ROS_INFO_STREAM("My message in upper case is: " << upper);

    // Reverse the converted string msg
    std::string backwards = "";
    for(int j = upper.length()-1; j > -1; j--)
        backwards += upper[j];
    ROS_INFO_STREAM("My message in upper case and backwards is: " << backwards);
}