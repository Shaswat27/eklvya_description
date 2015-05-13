#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

float i;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{

  ROS_INFO("rosservice call /gazebo/apply_joint_effort \"joint_name: 'joint2'\neffort: %s\nstart_time:\n  secs: 0\n  nsecs: 0\nduration:\n  secs:10\n  nsecs: 0\"", msg->data.c_str());


}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "velocity");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("topic_dummy", 1000, chatterCallback);

  

  ros::spin();
  return 0;
}
