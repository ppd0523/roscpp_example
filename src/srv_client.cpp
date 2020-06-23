#include "ros/ros.h"
#include "roscpp_example/Sum.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "srv_client");
    
    if(argc != 3){
        ROS_INFO("few arguments. Need 3");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient cli = nh.serviceClient<roscpp_example::Sum>("Sum");
    
    roscpp_example::Sum srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    if(cli.call(srv)){
        ROS_INFO("%d+%d=%d", (long int)srv.request.a, (long int)srv.request.b, (long int)srv.response.result);
    }
    else{
        ROS_ERROR("Service failed");
        return 1;
    }

    return 0;
}
