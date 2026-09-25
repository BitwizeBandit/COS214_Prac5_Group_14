#include "EmergencyCoordinator.h"

EmergencyCoordinator::EmergencyCoordinator(SecurityBuilding& s, MedicalBuilding& m, Facilities& f): colleagues{s, m, f}
{
    s.setMediator(*this); // deref 'this' bcs the param needs a obj, to get its reference in setMed()'s operation
    m.setMediator(*this);
    f.setMediator(*this);

}

void EmergencyCoordinator::notify(Building& originator) 
{
    for(Building& building : colleagues)
    {
        if(&building != &originator)
        {
            building.receiveEvacuationOrder();
        }
    }
}

EmergencyCoordinator::~EmergencyCoordinator(){}