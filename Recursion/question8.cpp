#include "question8.h"
#include <string>
#include <vector>
#include <iostream>

int MakeChange(int change, std::vector<int> & map)
{
    if (change < 0)
    {
        return 0;
    }
    if (map[change] != -1)
    {
        return map[change];
    }
    if (change == 0)
    {
        return 1;
    }
    else
    {
        map[change] = MakeChange(change - 25, map)  + MakeChange(change - 10, map) + MakeChange(change - 5, map) + MakeChange(change - 1, map);
        return  map[change];
    }
}

void Question8::Run()
{
    std::vector<int> map(101,-1);
    std::cout << "MakeChange(100): " << MakeChange(7, map) << std::endl;
}