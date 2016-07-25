#include <iostream>
#include "question1.h"
#include <vector>

int CountSteps(int steps, std::vector<int> & map)
{
    if (steps < 0)
    {
        return 0;
    }
    else if (map[steps] != -1)
    {
        return map[steps];
    }
    
    if (steps == 0)
    {
        return 1;
    }
    else
    {
        map[steps] = CountSteps(steps - 1, map) + CountSteps(steps - 2, map) + CountSteps(steps - 3, map);
        return map[steps];
    }
}

static void TestCase4()
{
    std::vector<int> map(251, -1);
    std::cout << "Combination of Step:" << CountSteps(250, map) << std::endl;
}

static void TestCase3()
{
    std::vector<int> map(101, -1);
    std::cout << "Combination of Step:" << CountSteps(100, map) << std::endl;
}

static void TestCase2()
{
    std::vector<int> map(51, -1);
    std::cout << "Combination of Step:" << CountSteps(50, map) << std::endl;
}

static void TestCase1()
{
    std::vector<int> map(100, -1);
    std::cout << "Combination of Step:" << CountSteps(4, map) << std::endl;
}

void Question1::Run()
{
    TestCase1();
    //TestCase2();
    //TestCase3();
    //TestCase4();
}