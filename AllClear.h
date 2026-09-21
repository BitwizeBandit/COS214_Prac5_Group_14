#ifndef ALLCLEAR_H
#define ALLCLEAR_H

#include "Command.h"

class AllClear : public Command
{
public:
    // AllClear(Team& team);
    virtual ~AllClear() = default;
    void solve() override; // Executes the all clear command on the receiver
};

#endif