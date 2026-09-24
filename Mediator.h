#ifndef MEDIATOR_H
#define MEDIATOR_H

class Building; // forward decl avoids circl include with Building.h

class Mediator 
{
    public:
        virtual void notify(Building&) = 0;
        virtual ~Mediator();

};

#endif // MEDIATOR_H