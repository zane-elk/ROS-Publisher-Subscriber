#include <r3_comm_network/letter_processor.h>

//Useful expressions
constexpr auto subjectA = "A: ";
constexpr auto subjectB = "B: ";
constexpr auto delimiter = ":";
constexpr auto bothSubjects = "AB: ";

// Initialise letter and format string
LetterProcessor::LetterProcessor(const std::string& msg)
{
    letter = msg;
    boost::algorithm::trim(letter);
}

// Determine if letter is for Mailbox A
bool LetterProcessor::checkForA()
{
    std::string msg_subject = letter.substr(0,3);
    return (msg_subject.compare(subjectA) == 0);
}

// Determine if letter is for Mailbox B
bool LetterProcessor::checkForB()
{
    std::string msg_subject = letter.substr(0,3);
    return (msg_subject.compare(subjectB) == 0);
}

// Determine if letter is for both Mailboxes
bool LetterProcessor::checkForBoth()
{
    std::string msg_subject = letter.substr(0,4);
    return ((letter.find(delimiter) == 2) && (msg_subject.compare(bothSubjects) == 0));
}