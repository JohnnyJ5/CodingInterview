#ifndef DISTINGUISHABLE_SET_H
#define DISTINGUISHABLE_SET_H

#include <vector>
#include <string>
#include "question.h"

class DistinguishableSet : public Question
{
public:
    void Run();
    
private:
    int count(const std::vector<std::string> & answer);
    void TestCase0();
    void TestCase1();
    void TestCase2();
    void TestCase3();
    void TestCase4();
};

#endif