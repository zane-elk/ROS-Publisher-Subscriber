#ifndef MAILMAN_H
#define MAILMAN_H

#include <r3_comm_network/comms_unit.h>

class Mailman : public CommsUnit
{
public:
    Mailman(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh);
    virtual void messageCallback(const std_msgs::String::ConstPtr& msg) override;
    void mailboxMessageCallback(const std_msgs::String::ConstPtr& msg);

private:
    ros::Publisher mPubList[3];
    ros::Subscriber mSubList[2];
};

#endif // MAILMAN_H