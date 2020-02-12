// I have neither given nor received any unauthorized aid in completing this work,
// nor have I presented someone else's work as my own
// Name: Austin Placinto
// Date: 2/5/2020

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <math.h>
// #include <iostream> // for debugging

using namespace std;

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
ros::Subscriber goal_subscriber;
turtlesim::Pose turtlesim_pose;

const double PI = 3.14159265359;
double deg2radians(double angle_in_degrees){
	return angle_in_degrees *PI /180.0;
}
const double BASE_LINEAR_SPEED = .7;
const double BASE_ANGULAR_SPEED = deg2radians(180);


void poseCallback(const turtlesim::Pose::ConstPtr& pose_msg) //get current x, y, orientation
{ 
	turtlesim_pose.x=pose_msg->x;
	turtlesim_pose.y=pose_msg->y;
	turtlesim_pose.theta=pose_msg->theta; // current absolute orientation of the turtle
}

// rotate from current orientation
void moveTurtle(const geometry_msgs::Point& point)
{
	geometry_msgs::Twist vel_msg;

    double target_angle = atan2 (point.y-turtlesim_pose.y, point.x-turtlesim_pose.x);
    double relative_angle_radians = target_angle - turtlesim_pose.theta;
    double linear_speed = BASE_LINEAR_SPEED * sqrt(pow(point.x-turtlesim_pose.x, 2) 
                                                        + pow(point.y-turtlesim_pose.y, 2));
    double angular_speed = BASE_ANGULAR_SPEED * (relative_angle_radians);

	vel_msg.linear.x = linear_speed;
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z = (relative_angle_radians > 0)? angular_speed : -angular_speed; 
	
	ros::Rate loop_rate(720);
	do {
        target_angle = atan2 (point.y-turtlesim_pose.y, point.x-turtlesim_pose.x);
        relative_angle_radians = target_angle - turtlesim_pose.theta;
        vel_msg.linear.x = BASE_LINEAR_SPEED * sqrt(pow(point.x-turtlesim_pose.x, 2) 
                                                        + pow(point.y-turtlesim_pose.y, 2));
        vel_msg.angular.z = BASE_ANGULAR_SPEED * (relative_angle_radians);
		velocity_publisher.publish(vel_msg);
		ros::spinOnce();
		loop_rate.sleep();
	} while(sqrt(pow(point.x-turtlesim_pose.x, 2) + pow(point.y-turtlesim_pose.y, 2)) > .3);
    vel_msg.linear.x = 0;
	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "go2xy_node");
	ros::NodeHandle n;
	velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
	pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);
	goal_subscriber = n.subscribe("/goal", 10, moveTurtle);
	ros::Rate loop_rate(0.2);
	
	ros::spin();
	return 0;
}
