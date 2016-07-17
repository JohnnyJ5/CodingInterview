/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "question5.h"
#include <iostream>
#include <vector>

enum Color
{
    Invalid = -1,
    Red = 0,
    Yellow = 1,
    Green = 2,
    Blue =3,
};

class Result
{
public:
    Result() : hit(0), pseudo_hit(0) {}
    int hit;
    int pseudo_hit;
};

Color convertChar(char c)
{
    switch (c)
    {
        case 'R':
            return Red;
        case 'Y':
            return Yellow;
        case 'G':
            return Green;
        case 'B':
            return Blue;
        default:
            return Invalid;
    }   
}

Result CalculateHits(const std::string & guess)
{
    const std::string solution("RGBY");
    std::vector<int> frequency_pseduo_hits(guess.size(), 0);
    if (solution.size() != guess.size())
    {
        std::cout << "Strings are incorrect sizes" << std::endl;
        return Result();
    }
    
    Result result;
    //Go through and determine the number of hits and the frequency of the 
    //colors in the solution text.
    for (auto i = 0; i < guess.size(); ++i)
    {
        if (convertChar(guess[i]) == convertChar(solution[i]))
        {
            ++result.hit;
        }
        else
        {
            Color color = convertChar(solution[i]);
            ++frequency_pseduo_hits[color];
        }
    }
    
    for (auto i = 0; i < guess.size(); ++i)
    {
        Color color = convertChar(guess[i]);
        if (color >= 0 && convertChar(guess[i]) != convertChar(solution[i]) && frequency_pseduo_hits[color] != 0)
        {
            ++result.pseudo_hit;
            --frequency_pseduo_hits[color];
        }
    }
    return result;
}

void Question5::Run()
{
    std::string guess;
    std::cout << "Enter a guess: " << std::endl;
    std::cin >> guess;
    
    Result result = CalculateHits(guess);
    std::cout << "The number of hits: " << result.hit << ", pseduo_hits: " << result.pseudo_hit << std::endl;
}