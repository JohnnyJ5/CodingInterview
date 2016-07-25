#include "question4.h"

#include <string>
#include <iostream>
#include <vector>


void PrintSubsets(const std::string & str)
{
    std::vector<std::string> subsets;
    int size = 0x01 << static_cast<int>(str.size());
    for (int subset = 0; subset < size; ++subset)
    {
        int i = subset;
        std::string s;
        int count = 0;
        while (i != 0)
        {
            if (i & 0x01 == 0x01)
            {
                s += str[count];
            }
            i >>= 1;
            count += 1;
        }
        subsets.push_back(s);
    }
    
    std::cout << "Number of subsets: " << subsets.size() << std::endl;
    int i = 0;
    for (auto it = subsets.begin(); it != subsets.end(); ++it, ++i)
    {
        std::cout << i << ": " << *it << std::endl;
    }
}

void Question4::Run()
{
    PrintSubsets("abc");
}