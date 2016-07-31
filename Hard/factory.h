
#include <memory>
#include "question.h"
#include "question4.h"

class Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() = 0;
};


class Question4Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance(){return std::shared_ptr<Question>(new Question4);}
};
