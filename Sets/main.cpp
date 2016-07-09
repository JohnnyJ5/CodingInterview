
#include <iostream>
#include <memory>
#include "factory.h"
#include <string>
#include <map>



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
    m["1"] = std::shared_ptr<Factory>(new DistinguishableSetFactory);

    QuestionMap::iterator it = m.find(argv[1]);
    if (it != m.end())
    {
        it->second->CreateInstance()->Run();
    }
    return 0;
}