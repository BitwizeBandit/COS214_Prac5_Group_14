#ifndef FIREEMERGENCYFACTORY_H
#define FIREEMERGENCYFACTORY_H

#include "Factory.h"
#include "FireEmergency.h"

class FireEmergencyFactory : public Factory
{
public:
    ~FireEmergencyFactory() override = default;
    // Command *create(Team &team) override;
};

#endif