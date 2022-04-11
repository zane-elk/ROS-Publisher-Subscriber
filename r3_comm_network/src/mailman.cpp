#include <r3_comm_network/mailman.h>
#include <r3_comm_network/letter_processor.h>

constexpr auto PUB_PO = "returns_PO";
constexpr auto PUB_A = "letters_A";
constexpr auto PUB_B = "letters_B";
constexpr auto SUB_A = "returns_A";
constexpr auto SUB_B = "returns_B";

// Initialise data members including all possible publish topics
Mailman::Mailman(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh) : CommsUnit(sub_id, pub_id, nh)
{
    mPubList[0] = nh.advertise<std_msgs::String>(PUB_A, 10, true);
    mPubList[1] = nh.advertise<std_msgs::String>(PUB_B, 10, true);
    mPubList[2] = nh.advertise<std_msgs::String>(PUB_PO, 10, true);
       
    mSubList[0] = nh.subscribe(SUB_A, 10, &Mailman::mailboxMessageCallback, this);
    mSubList[1] = nh.subscribe(SUB_B, 10, &Mailman::mailboxMessageCallback, this);
}

// Determine what topic to publish to based on letter subject
void Mailman::messageCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Mailman has received letter");

    //Process letter subject
    std::string msg_data = msg->data; 
    LetterProcessor lProc(msg_data);

    std::string msg_subject = msg_data.substr(0,3);

    // Decision process for mail delivery
    if(lProc.checkForBoth())
    {
        ROS_INFO("Sending Letter to Mailboxes A and B");
        mPub = mPubList[0];
        publishMessage(msg_data);
        mPub = mPubList[1];
    }
    else if (lProc.checkForA())
    {
        mPub = mPubList[0];
        ROS_INFO("Sending Letter to Mailbox A");
    }
    else if (lProc.checkForB())
    {
        mPub = mPubList[1];
        ROS_INFO("Sending Letter to Mailbox B");
    }
    else
    {
        mPub = mPubList[2];
        ROS_INFO("Returning to PO: Letter subject is not identifiable");
    }
    publishMessage(msg_data);
}

// Returns the letter to the post office
void Mailman::mailboxMessageCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("Mailman has received RETURNED letter");
    mPub = mPubList[2];
    publishMessage(msg->data);
}