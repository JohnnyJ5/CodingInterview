


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
    m["1"] = std::shared_ptr<Question1Factory>(new Question1Factory);
    m["2"] = std::shared_ptr<Question2Factory>(new Question2Factory);
    m["5"] = std::shared_ptr<Question5Factory>(new Question5Factory);
    m["6"] = std::shared_ptr<Question6Factory>(new Question6Factory);
    QuestionMap::iterator it = m.find(argv[1]);
    if (it != m.end())
    {
        it->second->CreateInstance()->Run();
    }
    
    
    return 0;
}