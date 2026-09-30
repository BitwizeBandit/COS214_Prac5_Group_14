#ifndef EMERGENCY_COORDINATOR_H
#define EMERGENCY_COORDINATOR_H

#include <vector>
#include <functional>
#include "Mediator.h"
#include "SecurityBuilding.h"
#include "MedicalBuilding.h"
#include "Facilities.h"

// Concrete_Mediator
// constructor enforces 'exactly one of each building type' at compile time,
//  and internally calls setMediator() on
// each Building so main() doesnt have to perform any separate connect step
class EmergencyCoordinator : public Mediator 
{
    private:
        std::vector<std::reference_wrapper<Building>> colleagues;

    public:
        EmergencyCoordinator(SecurityBuilding& s, MedicalBuilding& m, Facilities& f);
 
        void notify(Building& originator, MediatorEvent event) override;
 
        ~EmergencyCoordinator() override;

};

#endif //EMERGENCY_COORDINATOR_H