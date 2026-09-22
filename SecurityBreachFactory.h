#ifndef SECURITYBREACHFACTORY_H
#define SECURITYBREACHFACTORY_H

#include "Factory.h"
#include "SecurityBreach.h"

class SecurityBreachFactory : public Factory
{
public:
    ~SecurityBreachFactory() override = default;
    // Command* create(Team& team) override;
};

#endif