#include <r3_comm_network/post_office.h>

// Initialise data members
PostOffice::PostOffice(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh) : CommsUnit(sub_id, pub_id, nh){}

// Inform user of failure
void PostOffice::messageCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Returned letter received at PO: Mail did not reach correct mailbox");
}