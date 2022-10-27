#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/Int32.h"
#include <iostream>

sensor_msgs::Range msg1;

void number_callback(const sensor_msgs::Range::ConstPtr &msg)
{
    ROS_INFO("Distance from wall is %lf", msg->range);
    msg1.range = msg->range;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "stop_signal");
    ros::NodeHandle node1_obj;
    ros::Publisher warning_signal_publisher = node1_obj.advertise<std_msgs::Int32>("/warning_signal", 1000);
    ros::Subscriber stop_signal_subscriber = node1_obj.subscribe("/sensor_data", 1000, number_callback);
    ros::Rate loop_rate(10);
    std_msgs::Int32 msg2;

    while (ros::ok())
    {
        if(msg1.range >= 1){ // if distance is greater than 1 meter
            msg2.data = 1;
        }
        else{
            msg2.data = 0;
        }
        warning_signal_publisher.publish(msg2);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}