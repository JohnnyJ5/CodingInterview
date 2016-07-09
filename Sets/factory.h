#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include "question.h"
#include "distinguishable_set.h"


class Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() = 0;
};

class DistinguishableSetFactory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new DistinguishableSet);}
};

#endif