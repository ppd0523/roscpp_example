#include "ros/ros.h"
#include "roscpp_example/Msg.h"

void callback(const roscpp_example::Msg::ConstPtr& msg){
    ROS_INFO("%d", msg->value);   
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "msg_client");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("sample", 2, callback);

    ros::spin();
    return 0;
}
