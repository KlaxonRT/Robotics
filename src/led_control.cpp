// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 2/5/2020

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>
#include <string>

ros::Publisher pub;
bool prevState = false;

void callback_switch_led(const std_msgs::Int32& msg)
{
    std_msgs::Bool ledState;
    if(msg.data == 48)
    {
        prevState = false;
        ledState.data = false;
    }
    else if(msg.data == 49)
    {
        prevState = true;
        ledState.data = true;
    }
    else
    {
        ledState.data = prevState;
    }
    
    pub.publish(ledState);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "led_control");
    ros::NodeHandle nh;

    std::string led_color = "/red_led";
    nh.getParam("/color", led_color);
    ros::Subscriber sub = nh.subscribe("/keyboard", 1000,
        callback_switch_led);
    pub = nh.advertise<std_msgs::Bool>(led_color, 10);
    ros::spin();
}