#ifndef ALLCLEARFACTORY_H
#define ALLCLEARFACTORY_H

#include "Factory.h"
#include "AllClear.h"

class AllClearFactory : public Factory
{
public:
    ~AllClearFactory() override = default;
    // Command *create(Team &team) override;
};

#endif