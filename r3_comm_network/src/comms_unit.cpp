#include <r3_comm_network/comms_unit.h>

// Initialise publisher and subscriber
CommsUnit::CommsUnit(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh)
{
    mSub = nh.subscribe(sub_id, 10, &CommsUnit::messageCallback, this);
    mPub = nh.advertise<std_msgs::String>(pub_id, 10, true);
    ROS_INFO("Comms unit initialised");
}

// Generic publishing procedure
void CommsUnit::publishMessage(const std::string& pub_msg)
{
    std_msgs::String msg;
    msg.data = pub_msg;
    mPub.publish(msg);
    ROS_INFO("Letter in transit");
}