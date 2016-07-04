
#include <memory>
#include "question.h"
#include "question1.h"
#include "question2.h"
#include "question5.h"
#include "question6.h"

class Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() = 0;
};

class Question1Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question1);}
};

class Question2Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question2);}
};

class Question5Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question5);}
};

class Question6Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question6);}
};