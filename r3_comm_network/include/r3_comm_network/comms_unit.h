#ifndef COMMS_UNIT_H
#define COMMS_UNIT_H

#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/String.h>

class CommsUnit
{
public:
    CommsUnit(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh);
    virtual void messageCallback(const std_msgs::String::ConstPtr& msg) = 0;
    void publishMessage(const std::string& pub_msg);

protected:
    ros::Publisher mPub;
    ros::Subscriber mSub;
};

#endif // COMMS_UNIT_H