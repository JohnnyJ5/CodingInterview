

#include "question4.h"
#include <iostream>

int NumberOf2(const int n)
{
    int count = 0;
    for (auto i = n; i >= 2; --i)
    {
        int tmp = i;
        while (tmp != 0)
        {   
            if (tmp % 10 == 2)
            {
                ++count;
            }
            
            tmp /= 10;
        }
    }
    
    return count;
}


void Question4::Run()
{
    int n = 13;
    std::cout << "NumberOf2(" << n << "): " << NumberOf2(n) << std::endl;
    n = 5; std::cout << "NumberOf2(" << n << "): " << NumberOf2(n) << std::endl;
    n = 25; std::cout << "NumberOf2(" << n << "): " << NumberOf2(n) << std::endl;
    n = 30; std::cout << "NumberOf2(" << n << "): " << NumberOf2(n) << std::endl;
}