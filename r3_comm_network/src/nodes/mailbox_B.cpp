#include <r3_comm_network/mailbox.h>

constexpr auto NODE_NAME = "mailbox_B_node";
constexpr auto SUB_ID = "letters_B";
constexpr auto PUB_ID = "returns_B";
constexpr char ID = 'B';

// Create ROS node
int main(int argc, char **argv)
{
    ros::init(argc, argv, NODE_NAME);
    ros::NodeHandle nh;
    Mailbox node(SUB_ID, PUB_ID, nh, ID);
    ros::spin();

    return 0;
}