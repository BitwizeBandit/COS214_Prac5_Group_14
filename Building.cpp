#include "Building.h"

Building::Building(): locked(false), occupied(false), mediator(nullptr) {}

Building::~Building() {}

// Called once by the Mediator that owns this Colleague (like in Mediator's constructor) to complete the connection
void Building::setMediator(Mediator& mediatorRef)
{
    mediator = &mediatorRef;
}

// Legacy style toggle method (our Adaptee interface for BuildingAdapter)
void Building::toggleLocked()
{
    locked = !locked;
}

bool Building::getLocked() const
{
    return locked;
}

// Called by a Team (or any client) to trigger this Building's own evac, 
// then notify the Mediator so it can coordinate the others
// If no Mediator has been registered yet, this is a no op rather than a crash
void Building::evacuate()
{
    doEvacuate();

    if(mediator != nullptr)
    {
        mediator->notify(*this);
    }
}

// Called by the Mediator on the Other Colleagues
// Running the local evac only, does not call notify() again, so this cannot recurse
void Building::receiveEvacuationOrder()
{
    doEvacuate();
}