/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "question5.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int BinarySearch(const std::vector<std::string> & v, const std::string & x)
{
    int left = 0;
    int right = v.size() - 1;
    int mid;
    
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (v[mid] < x)
        {
            left = mid + 1;
        }
        else if (v[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int BinarySearchEmptySpaces(const std::vector<std::string> & v, const std::string & x)
{
    int left = 0;
    int right = v.size() - 1;
    int mid;
    
    while (left <= right)
    {
        mid = (left+right)/2;
        
        //Find first non space going left or right.
        if (v[mid] == "a")
        {
            int left_end = mid;
            int right_start = mid;
            for (unsigned int i = 0; i < v.size() / 2; ++i)
            {
                left_end = std::max<int>(left_end - i - 1, left);
                right_start = std::min<int>(right_start + i + 1, right);
                if (v[left_end] != "a")
                {
                    //std::cout << "left_end" << std::endl;
                    mid = left_end;
                    break;
                }
                if (v[right_start] != "a")
                {
                    //std::cout << "right_start" << std::endl;
                    mid = right_start;
                    break;
                }
                if (left_end == left && right_start == right)
                {
                    return -1;
                }
            }
        }
        
        if (v[mid] < x)
        {
            left = mid + 1;
        }
        else if (v[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void Question5::Run()
{
    std::cout << "Running Question 3" << std::endl;
    std::vector<std::string> v {"at", "ball", "car", "dad", "finger", "graph"};
    std::cout << "BinarySearch(\"dad\"): " << BinarySearch(v, "dad") << std::endl;
    std::cout << "BinarySearch(\"pork\"): " << BinarySearch(v, "pork") << std::endl;
    std::cout << "BinarySearch(\"at\"): " << BinarySearch(v, "at") << std::endl;
    std::cout << "BinarySearch(\"ask\"): " << BinarySearch(v, "ask") << std::endl;
    
    std::vector<std::string> vs {"at", "a", "a", "a", "ball", "a", "a", "car", "a", "a", "dad", "a", "a"};
    std::cout << "BinarySearchEmptySpaces(\"dad\"): " << BinarySearchEmptySpaces(vs, "dad") << std::endl;
    std::cout << "BinarySearchEmptySpaces(\"pork\"): " << BinarySearchEmptySpaces(vs, "pork") << std::endl;
    std::cout << "BinarySearchEmptySpaces(\"at\"): " << BinarySearchEmptySpaces(vs, "at") << std::endl;
    std::cout << "BinarySearchEmptySpaces(\"ask\"): " << BinarySearchEmptySpaces(vs, "ask") << std::endl;
}