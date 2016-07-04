
#include "question1.h"
#include <vector>
#include <iostream>


void PrintVector(const std::string & title, const std::vector<int> & v)
{
    std::cout << title << std::endl;
    for (unsigned int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


//Note this could be simplified by just going through array b because once we
//are done with b a is in sorted order already.
void Question1::Run()
{
    std::cout << "Running Question 1" << std::endl;
    
    std::vector<int> a {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> b {2,4,6,8,10,12,14,16,18,20};
    a.resize(a.size() + b.size());  //Pad a with zeros to include size of b.
    
    PrintVector("Vector a",a);
    PrintVector("Vector b",b);
    
    int a_end = 0;
    while (a[a_end] != 0) { ++a_end; }
    --a_end;
    int b_end = b.size() - 1;
    
    //Go through comparing the end of a and b.
    int c_end = a.size() - 1;
    while (a_end >= 0 || b_end >= 0)
    {
        if (a_end < 0)
        {
            a[c_end] = b[b_end--];
        }
        if (b_end < 0)
        {
            a[c_end] = a[a_end--];
        }
        if (a[a_end] <= b[b_end])
        {
            a[c_end] = b[b_end--];
        }
        else
        {
            a[c_end] = a[a_end--];
        }
        
        --c_end;
    }
    
    PrintVector("In Sorted Order", a);
}