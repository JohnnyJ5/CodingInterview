#include "question9.h"
#include <string>
#include <vector>
#include <iostream>

static const int GRID_SIZE = 8;

bool ValidPlaceForQueen(int row, std::vector<int> & columns, int col)
{
    //Check for all rows up to now if we have a queen in that spot already.
    //This means checking if the queen is in that column and whether 
    //there is a queen in the diagnol already.  Since we build up the rows from
    //0 to 8 we only need to check up to what we placed so far.
    for (int row2 = 0; row2 < row; ++row2)
    {
        //Check if for the row we have a queen there already.
        if (columns[row2] == col)
        {
            return false;
        }
        
        int columnDistance = abs(col - columns[row2]);
        int rowDistance = row - row2;
        if (columnDistance == rowDistance)
        {
            return false;
        }
    }
    return true;
}

void PlaceQueen(int row, std::vector<int> & columns, std::vector<std::vector<int> > & result)
{
    if (row == GRID_SIZE)
    {
        result.push_back(columns);
    }
    else
    {
        //Build up the solution.  Try and add the queen to each column in the row
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (ValidPlaceForQueen(row, columns, j))
            {
                columns[row] = j;
                PlaceQueen(row + 1, columns, result);
            }
        }
    }
}

void Question9::Run()
{
    std::vector<int> columns(8,0);
    std::vector<std::vector<int> > result;
    PlaceQueen(0, columns, result);
    
    std::cout << "Number of valid placements: " << result.size() << std::endl;
    for (unsigned int i = 0; i < result.size(); ++i)
    {
        std::cout << "solution(" << i << "): ";
        for (unsigned int j = 0; j < result[i].size(); ++j)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}