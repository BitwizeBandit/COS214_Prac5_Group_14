#ifndef MEDIATOR_H
#define MEDIATOR_H

class Building; // forward decl avoids circl include with Building.h

// What kind of change a Colleague is reporting
enum class MediatorEvent { EVACUATE, ALL_CLEAR };

class Mediator 
{
    public:
        virtual void notify(Building& originator, MediatorEvent event) = 0; // passing which event needs to happen
        virtual ~Mediator();

};

#endif // MEDIATOR_H