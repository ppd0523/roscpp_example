#include "ros/ros.h"
#include "roscpp_example/Msg.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "msg_server");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<roscpp_example::Msg>("sample", 1);

    ros::Duration duration(1);

    int cnt = 0;
    while(ros::ok()){
        roscpp_example::Msg msg;
        msg.value = cnt;
        ROS_INFO("%d", cnt);
        pub.publish(msg);

        duration.sleep();
        
        ++cnt;
    }

    ros::spin();
    return 0;
}
