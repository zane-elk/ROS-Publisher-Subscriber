#ifndef POST_OFFICE_H
#define POST_OFFICE_H

#include <r3_comm_network/comms_unit.h>

class PostOffice : public CommsUnit
{
public:
    PostOffice(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh);
    virtual void messageCallback(const std_msgs::String::ConstPtr& msg) override;
};

#endif // POST_OFFICE_H