/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "question6.h"
#include <vector>
#include <string>
#include <iostream>

bool Find(int *m, int len, int val)
{
    //Start at greatest column and lowest row.
    int row = 0;
    int col = len - 1;
    while (row < len && col >= 0)
    {
        if (m[row * len + col] == val)
        {
            return true;
        }
        else if (m[row * len + col] > val)
        {
            --col;
        }
        else
        {
            ++row;
        }
    }
    //return false;
    row = 0;
    col = 0;
    while (row < len && col < len)
    {
        if (m[row * len + col] == val)
        {
            return true;
        }
        else if (m[row * len + col] < val)
        {
            ++col;
        }
        else
        {
            ++row; col = 0;
        }
    }
    return false;
}

void Question6::Run()
{
    std::cout << "Running Question 6" << std::endl;
    
    int matrix[5][5] = {15, 20, 40, 85, 90,
                        20, 35, 80, 95, 100,
                        30, 55, 95, 105, 110,
                        40, 80, 100, 120, 130,
                        50, 90, 110, 130, 140};
    
    for (auto i = 0 ; i < 5; ++i)
    {
        for (auto j = 0; j < 5; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Find(0): " << Find(&matrix[0][0], 5, 0) << std::endl;
    std::cout << "Find(80): " << Find(&matrix[0][0], 5, 80) << std::endl;
    std::cout << "Find(101): " << Find(&matrix[0][0], 5, 101) << std::endl;
    std::cout << "Find(202): " << Find(&matrix[0][0], 5, 202) << std::endl;      
}