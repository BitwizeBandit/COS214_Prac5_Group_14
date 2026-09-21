#ifndef SECURITYBREACH_H
#define SECURITYBREACH_H

#include "Command.h"

class SecurityBreach : public Command
{
public:
    // SecurityBreach(Team& team);
    ~SecurityBreach() override = default;
    void solve() override;
};

#endif