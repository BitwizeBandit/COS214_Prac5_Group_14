#include "Building.h"

Building::Building(): locked(false), occupied(false), evacuated(false), mediator(nullptr) {}

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
    if (evacuated) 
    {
        return; // already evaced, so its redundant call, I handled as a no op
    }

    evacuated = true;
    doEvacuate();

    if (mediator != nullptr) 
    {
        mediator->notify(*this, MediatorEvent::EVACUATE);
    }
}

void Building::allClear() 
{
    if (!evacuated) 
    {
        return; // nothing to clear, so its redundant call, Im handling as a no op
    }

    evacuated = false;
    doAllClear();

    if (mediator != nullptr) 
    {
        mediator->notify(*this, MediatorEvent::ALL_CLEAR);
    }
}

// Called by the Mediator on the Other Colleagues
// Running the local evac only, does not call notify() again, so this cannot recurse
void Building::receiveEvacuationOrder()
{
    if (evacuated) 
    {
        return;
    }

    evacuated = true;
    doEvacuate();
}

void Building::receiveAllClearOrder() 
{
    if (!evacuated) 
    {
        return;
    }
    
    evacuated = false;
    doAllClear();
}