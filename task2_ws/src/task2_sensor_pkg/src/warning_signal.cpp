#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void number_callback1(const std_msgs::Int32::ConstPtr& msg2){
    if(msg2->data==1){
    ROS_INFO("%d NO WARNING!",msg2->data);
    }
    else{
    ROS_INFO("%d WARNING !",msg2->data);
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "warning_signal");
    ros::NodeHandle node3_obj;
    ros::Subscriber warning_signal_subscriber= node3_obj.subscribe("/warning_signal",1000,number_callback1);
    ros::spin();
    return 0;
}