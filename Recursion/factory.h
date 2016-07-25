
#include <memory>
#include "question.h"
#include "question1.h"
#include "question4.h"
#include "question5.h"
#include "question8.h"
#include "question9.h"

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

class Question4Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question4);}
};

class Question5Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question5);}
};

class Question8Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question8);}
};

class Question9Factory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new Question9);}
};

