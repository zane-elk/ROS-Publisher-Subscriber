#include <r3_comm_network/mailbox.h>
#include <r3_comm_network/letter_processor.h>

// Initialise class data members
Mailbox::Mailbox(const std::string& sub_id, const std::string& pub_id, ros::NodeHandle nh, char id) : CommsUnit(sub_id, pub_id, nh){
    mId = id;
}

// Verify delivered mail matches the mailbox delivered to
void Mailbox::messageCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Mailbox %c has received letter", mId);
    
    std::string msg_data = msg->data; 
    LetterProcessor lProc(msg_data); // Create instance of letter processing class

    // Evaluate whether mail belongs in the mailbox
    if(mId == 'A' && (lProc.checkForA() || lProc.checkForBoth()))
    {
        ROS_INFO("Correct letter received at A"); 
    }
    else if(mId == 'B' && (lProc.checkForB() || lProc.checkForBoth()))
    {
        ROS_INFO("Correct letter received at B"); 
    }
    else
    {
        ROS_INFO("Returning letter: Incorrect letter received"); 
        publishMessage(msg_data); // return the letter to PO box if it doesnt belong
    }
}