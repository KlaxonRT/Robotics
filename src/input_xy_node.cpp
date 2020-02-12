// I have neither given nor received any unauthorized aid in completing this work,
// not have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 2/12/2020

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
    ros::init(argc, argv, "input_xy_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Point>(
        "/goal", 10);

    while(ros::ok()) {
        geometry_msgs::Point msg;
        double x, y;
        cout << "--------------------------\n";
        cout << "Enter x: ";
        cin >> x;
        while (cin.fail() || !(x >= 0 && x <= 11))
        {
            cout << "Out of bounds, between 0-11: ";
            cin.clear();
            cin.ignore(123, '\n');
            cin >> x;
        }
        cout << "Enter y: ";
        cin >> y;
        while (cin.fail() || !(y >= 0 && y <= 11))
        {
            cout << "Out of bounds, between 0-11: ";
            cin.clear();
            cin.ignore(123, '\n');
            cin >> y;
        }
        msg.x = x;
        msg.y = y;
        pub.publish(msg);
    }
}