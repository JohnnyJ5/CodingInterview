#include "distinguishable_set.h"
#include <set>
#include <iostream>
#include <math.h>

//The underlying problem:  Find all subsets of answers that are distinct.
//1) Loop through the number of subsets minus the empty set so there are
//   2^M - 1 subsets where M is the length of each persons answer.
//2) We determine a subset by incrementing an integer starting from 0.
//   When a bit is set to 1 it is in the subset otherwise it is not.   
//   We loop through the integer masking it with 0x1 and keeping track of the bit position while will index into a persons answer and create the subset.  
//   After we have the subset we insert into a set.  If all answers are distinct the size of the set should equal the number of people.

int DistinguishableSet::count(const std::vector<std::string> & answer)
{
    int distinguishable_subsets = 0;  //Empty set always counts.
    int number_of_subsets = pow(2, answer[0].size()) - 1;
    for (int subset = 1; subset <= number_of_subsets; ++subset)
    {
        std::set<std::string> set;

        //Go through all the people's answers and get the subset and insert the answer into a set.
        for (unsigned int a = 0; a < answer.size(); ++a)
        {
            int mask = subset;
            int count = 0;
            std::string persons_answer;
            while ( mask != 0)
            {
                if ((mask & 0x00000001) == 1)
                {
                    persons_answer += answer[a][count];
                }
                mask = mask >> 1;
                ++count;

            }
            //std::cout << "subset: " << subset << " inserting " << persons_answer << std::endl;
            set.insert(persons_answer);
        }
        if (set.size() == answer.size())
        {
            distinguishable_subsets++;
        }
    }
    return distinguishable_subsets;
}

void DistinguishableSet::TestCase0()
{
    std::vector<std::string> answer = {"AA", "AB", "CC"};
    int subsets = count(answer);
    if (subsets == 2)
    {
        std::cout << "Test Passed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed, subsets: " << subsets << std::endl;
    }
}
void DistinguishableSet::TestCase1()
{
    std::vector<std::string> answer = {"XYZ","XYZ","XYZ"};
    int subsets = count(answer);
    if (subsets == 0)
    {
        std::cout << "Test Passed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed, subsets: " << subsets << std::endl;
    }
}
void DistinguishableSet::TestCase2()
{
    std::vector<std::string> answer = {"AAAA","BACA","CDCE"};
    int subsets = count(answer);
    if (subsets == 11)
    {
        std::cout << "Test Passed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed, subsets: " << subsets << std::endl;
    }
}
void DistinguishableSet::TestCase3()
{
    std::vector<std::string> answer = {"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"};
    int subsets = count(answer);
    if (subsets == 1017)
    {
        std::cout << "Test Passed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed, subsets: " << subsets << std::endl;
    }
}
void DistinguishableSet::TestCase4()
{
    std::vector<std::string> answer = {"XYZ","XAB","YAC"};
    int subsets = count(answer);
    if (subsets == 5)
    {
        std::cout << "Test Passed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed, subsets: " << subsets << std::endl;
    }
}

void DistinguishableSet::Run()
{
    TestCase0();
    TestCase1();
    TestCase2();
    TestCase3();
    TestCase4();    
}