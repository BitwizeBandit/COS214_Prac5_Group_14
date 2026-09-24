#ifndef BUILDING_H
#define BUILDING_H
 
#include "Mediator.h"

// Colleague-abstract for Mediator, also Adaptee for BuildingAdapterImpl
class Building
{
    protected:
        bool locked;
        bool occupied;

        // a Building can be constructed before its mediator is connected, like with setMediator()
        Mediator* mediator;

        // Concr Colleagues impl their own local evac behaviour here
        virtual void doEvacuate() = 0;

    public:
        Building();
        virtual ~Building();

        // Called once by the Mediator that owns this Colleague (like in Mediator's constructor) to complete the connection
        void setMediator(Mediator& mediator);

        // Legacy style toggle method (our Adaptee interface for BuildingAdapter)
        void toggleLocked();
        bool getLocked() const;

        // Called by a Team (or any client) to trigger this Building's own evac, 
        // then notify the Mediator so it can coordinate the others
        // If no Mediator has been registered yet, this is a no op rather than a crash
        void evacuate();

        // Called by the Mediator on the Other Colleagues
        // Running the local evac only, does not call notify() again, so this cannot recurse
        void receiveEvacuationOrder();
};

#endif // BUILDING_H