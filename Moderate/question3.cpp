/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "question3.h"
#include <iostream>
#include <vector>

std::vector<int> cache(255,0);

void factorial(auto n)
{
    //The number of trailing zeros for a factorial is the sum of the 
    //number of 5s found in all the factorials.
    auto sum_5 = 0;
    for (auto i = n; i >= 2; --i)
    {
        if (cache[i] != 0)
        {
            sum_5 += cache[i];
        }
        else
        {
            auto count = 0;
            auto num = i;
            while (num % 5 == 0)
            {
                num /= 5;
                count++;
            }
            cache[i] = count;
            sum_5 += cache[i];
        }
    }
    
    std::cout << "Number of trailing zeros for " << n << "! is " << sum_5 << std::endl;
}

void Question3::Run()
{
    for (auto i = 35; i >= 0; --i)
    {
        factorial(i);
    }
}