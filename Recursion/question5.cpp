#include "question5.h"
#include <string>
#include <vector>
#include <iostream>


std::string InsertCharacter(std::string character, std::string word, unsigned int pos)
{
    std::string first = word.substr(0,pos);
    std::string second = word.substr(pos);
    return first + character + second;
}

std::vector<std::string> Permutations(const std::string & str)
{
    
    std::vector<std::string> perms;
    if (str.empty())
    {
        perms.push_back("");
        return perms;
    }
    
    //get the first charcater and the remainder.
    std::string first = str.substr(0,1);
    std::string remainder = str.substr(1);
//    std::cout << "remainder: " << remainder << std::endl;
    std::vector<std::string> words = Permutations(remainder);
    for (auto it = words.begin(); it != words.end(); ++it)
    {
        for (unsigned int i = 0; i <= it->size(); ++i)
        {
            std::string s = InsertCharacter(first, *it, i);
//            std::cout << "push_back: " << s << std::endl;
            perms.push_back(s);
        }
    }
    return perms;
}

void Question5::Run()
{
    std::vector<std::string> v = Permutations("abc");
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}