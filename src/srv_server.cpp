#include "ros/ros.h"
#include "roscpp_example/Sum.h"

bool sumCB(roscpp_example::Sum::RequestType& req, roscpp_example::Sum::Response& res){
    res.result = req.a + req.b;
    ROS_INFO("%d+%d=%d", (long int)req.a, (long int)req.b, (long int)res.result);
    return true;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "srv_server");
    
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("Sum", sumCB);

    ROS_INFO("Service Server ready");

    ros::spin();
    return 0;
}
