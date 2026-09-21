#ifndef FIREEMERGENCY_H
#define FIREEMERGENCY_H

#include "Command.h"

class FireEmergency : public Command
{
public:
    // FireEmergency(Team& team);
    ~FireEmergency() override = default;
    void solve() override;
};

#endif