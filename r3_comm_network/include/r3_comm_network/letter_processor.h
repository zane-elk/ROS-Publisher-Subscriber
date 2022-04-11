#ifndef LETTER_PROCESSOR_H
#define LETTER_PROCESSOR_H

#include <boost/algorithm/string/trim.hpp>

class LetterProcessor
{
public:
    LetterProcessor(const std::string& msg);
    bool checkForA();
    bool checkForB();
    bool checkForBoth();

private:
    std::string letter;
};

#endif // LETTER_PROCESSOR_H