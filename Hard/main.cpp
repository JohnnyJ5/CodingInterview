


#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <algorithm>

#include "factory.h"

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        std::cout << "Usgage: <executable> <problem number>" << std::endl;
        return 1;
    }
    
    //Create map of questions to run.
    typedef std::map<std::string, std::shared_ptr<Factory> > QuestionMap;
    QuestionMap m;
    m["4"] = std::shared_ptr<Factory>(new Question4Factory);


    QuestionMap::iterator it = m.find(argv[1]);
    if (it != m.end())
    {
        it->second->CreateInstance()->Run();
    }
    
    
    return 0;
}