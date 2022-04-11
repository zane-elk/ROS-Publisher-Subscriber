#ifndef MAILBOX_H
#define MAILBOX_H

#include <r3_comm_network/comms_unit.h>

class Mailbox : public CommsUnit
{
public:
    Mailbox(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh, char id);
    virtual void messageCallback(const std_msgs::String::ConstPtr& msg) override;

private:
    char mId;
};

#endif // MAILBOX_H