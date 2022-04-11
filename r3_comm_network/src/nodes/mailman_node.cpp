#include <r3_comm_network/mailman.h>

constexpr auto NODE_NAME = "mailman_node";
constexpr auto SUB_ID = "letters_PO";
constexpr auto PUB_ID = "returns_PO";

// Create ROS node
int main(int argc, char **argv)
{
    ros::init(argc, argv, NODE_NAME);
    ros::NodeHandle nh;
    Mailman node(SUB_ID, PUB_ID, nh);
    ros::spin();

    return 0;
}