#ifndef COMMAND_H
#define COMMAND_H

// class Team;

class Command
{
protected:
    // Team& team;
public:
    // Command(Team& team);
    virtual ~Command() = default;
    virtual void solve() = 0;
};

#endif