#include <r3_comm_network/post_office.h>
#include <fstream>

constexpr auto NODE_NAME = "post_office_node";
constexpr auto SUB_ID = "returns_PO";
constexpr auto PUB_ID = "letters_PO";

// Create ROS node
int main(int argc, char **argv)
{
    ros::init(argc, argv, NODE_NAME);
    ros::NodeHandle nh;
    PostOffice node(SUB_ID, PUB_ID, nh);
    
    std::string msg = "B: This is the message"; // Input message

    ROS_INFO("Message is: \"%s\" ", msg.c_str());
    ROS_INFO("Sending out message from PO");
    node.publishMessage(msg);
    ros::spin();

    return 0;
}