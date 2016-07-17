/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "question6.h"
#include <iostream>
#include <vector>


void Question6::Run()
{
    std::vector<int> a = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    
    //Start at the beginning and determine where in the array it breaks the index.
    auto s = 0;
    auto e = a.size() - 1;
    for (auto i = 0; i < a.size() - 1; ++i)
    {
        //Array should be in increasing order.  Find the point that isn't increasing
        if (a[i] > a[i+1])
        {
            s = i + 1;
            break;
        }
    }
    
    for (auto i = a.size() - 1; i > 0; --i)
    {
        //Array should be in decreasing order.  Find the point that isnt
        if (a[i] < a[i-1])
        {
            e = i - 1;
            break;
        }
    }
    
    std::cout << "Round 1 (s,e) index: (" << s << "," << e << ")" << std::endl;
    
    //Determine where s should be in the front of the array.  Walk backwards from s.
    for (auto i = s - 1; i > 0; --i)
    {
        if (a[s] >= a[i])
        {
            s = i + 1;
            break;
        }
    }
    
    for (auto i = e + 1; i < a.size() - 1; ++i)
    {
        if ( a[e] <= a[i] )
        {
            e = i - 1;
            break;
        }
    }
    
    std::cout << "Round 2 (s,e) index: (" << s << "," << e << ")" << std::endl;
    
    //Find the min and max of the range from s to e
    int min = a[s];
    int max = a[s];
    for (auto i = s+1; i <= e; ++i)
    {
        min = std::min(min, a[i]);
        max = std::max(max, a[i]);
    }
    
    std::cout << "Round 3 (min,max) value: (" << min << "," << max << ")" << std::endl;
    
    //Now determine how far back to go with s or forward to go with e to get the absolute bounds.
    for (auto i = s; i > 0; --i)
    {
        if (a[i] <= min)
        {
            s = i + 1;
            break;
        }
    }
    
    for (auto i = e; i < a.size() -1; ++i)
    {
        if (a[i] >= max)
        {
            e = i - 1;
            break;
        }
    }
    
    std::cout << "Finished - (min,max) index: (" << s << "," << e << ")" << std::endl;
    
}