


#include <unordered_map>
#include <iostream>
#include <algorithm>

bool IsPalindrome(const std::string & str)
{
    for (int i = 0; i < static_cast<int>(str.size() / 2); ++i)
    {
        if (str[i] != str[str.size()-1-i])
        {
            return false;
        }
    }
    
    return true;
}

void MatchingGloves(const std::vector<std::string> & input)
{
    std::vector<std::string> gloves;
    for (auto it = input.begin(); it != input.end(); ++it)
    {
        if (!IsPalindrome(*it))
        {
            gloves.push_back(*it);
        }
    }
    
    std::cout << "Gloves size: " << gloves.size() << std::endl;
    if (gloves.size() % 2 == 1)
    {
        std::cout << "Odd number of gloves.  They can't match" << std::endl;
        return;
    }
    
    std::unordered_multimap<std::string, int> m;
    for (auto it = gloves.begin(); it != gloves.end(); ++it)
    {
        auto findIt = m.find(*it);
        if (findIt == m.end())
        {
            m.insert(std::make_pair(*it, 1));
        }
        else
        {
            findIt->second++;
        }
    }
    for ( auto& x: m )
        std::cout << x.first << ": " << x.second << std::endl;
    
    int num_pairs = 0;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        std::string s = it->first;
        std::reverse(s.begin(), s.end());
        auto revIt = m.find(s);
        if (revIt == m.end())
        {
            std::cout << "Not all gloves match" << std::endl;
            return;
        }
        else
        {
            if (it->second == revIt->second)
            {
                num_pairs += it->second;
            }
            else
            {
                std::cout << "Not all gloves match" << std::endl;
                return;
            }
        }
    }
    
    if (num_pairs % 2 == 0)
    {
        std::cout << "Number of matching pairs of gloves: " << num_pairs / 2 << std::endl;
    }
    else
    {
        std::cout << "Not all gloves match" << std::endl;
    }
}


void TestCase1()
{
    std::vector<std::string> v = {"abc", "def", "aba", "fed", "cba"};
    MatchingGloves(v);
}

void TestCase2()
{
    std::vector<std::string> v = {"abc", "def", "aba", "fed"};
    MatchingGloves(v);
}

void TestCase3()
{
    std::vector<std::string> v = {"abc", "def", "abc", "cba", "fed", "def"};
    MatchingGloves(v);
}

int main()
{
    TestCase1();
    TestCase2();
    TestCase3();
    return 0;
}