#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "dummy");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_dummy", 1000);
  ros::Rate loop_rate(0.5);
  float velocity = 1;
  while (ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << velocity;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    velocity = velocity+0.3 ;
	ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
