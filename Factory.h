#ifndef FACTORY_H
#define FACTORY_H

class Command;
// class Team;

class Factory
{
public:
    virtual ~Factory() = default;
    // virtual Command *create(Team &team) = 0;
};

#endif