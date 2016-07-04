/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "question2.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

void PrintVector(const std::string & title, const std::vector<std::string> & v)
{
    std::vector<std::string>::const_iterator it = v.begin();
    std::cout << title << std::endl;
    for(; it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


//At first I used a std::unorderd_map but when I did an insert with a duplicate key
//The insert failed.  the unordered_map has collision resolution but with different key values
//If two different keys hash to the same bucket then thats fine.

//Solution was to use a std::unordered_multimap that allows you to add duplicate keys with different values.
void GroupAnagramsByHash()
{
    std::vector<std::string> v {"the", "sasp", "zap", "acre", "paz", "race", "eth", "pass"};
    PrintVector("Initial Vector", v);
    std::unordered_multimap<std::string, std::string> m;
//    m.reserve(25);
    auto it = v.begin();
    for(; it != v.end(); ++it)
    {
        auto s = *it;
        std::sort(s.begin(), s.end());
        auto insert = m.insert(std::pair<std::string, std::string>(s,*it));
    }
    std::cout << "My map contains: " << std::endl;
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << ":" << it->second << " ";
    }
    std::cout << std::endl;
    std::cout << "Group Anagrams by std::unorderd_multimap" << std::endl;
    for (auto i = 0; i < m.bucket_count(); ++i)
    {
//        std::cout << "bucket #: " << i << " contains: ";
        for(auto it = m.begin(i); it != m.end(i); ++it)
        {
            std::cout << it->second << " ";
        }
//        std::cout << std::endl;
    }
}

bool CompareAnagram(std::string lhs, std::string rhs)
{
    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    return lhs < rhs;
}

void GroupAnagramsBySorting()
{
    std::vector<std::string> v {"the", "zap", "acre", "paz", "race", "eth", "pass"};
    PrintVector("Initial Vector", v);
    std::sort(v.begin(), v.end(), CompareAnagram);
    PrintVector("Group Anagrams By Sorting", v);
    
}

void Question2::Run()
{
    std::cout << "Running Question 2" << std::endl;
     
    GroupAnagramsBySorting();
    std::cout << std::endl;
    GroupAnagramsByHash();
}