#include <iostream>
#include "WorkFlow.h"
#include "Team.h"
#include "Command.h"
#include "EmergencyCoordinator.h"
#include "BuildingAdapterImpl.h"
#include "FireEmergencyFactory.h"
#include "MedicalEmergencyFactory.h"
#include "SecurityBreachFactory.h"
#include "AllClearFactory.h"
#include "Facilities.h"
#include "MedicalBuilding.h"
#include "SecurityBuilding.h"

void WorkFlow::fireDrill()
{
	std::cout << "===== Fire drill =====" << std::endl;

	// Buildings, then the mediator that links them (stack allocated, this workflow owns them all)
	SecurityBuilding securityBuilding;
	MedicalBuilding medicalBuilding;
	Facilities facilities;
	EmergencyCoordinator coordinator(securityBuilding, medicalBuilding, facilities);

	// Decorator stack: every team responds to a fire
	BasicTeam basicTeam;
	MedicalTeam medicalTeam(&basicTeam, &medicalBuilding);
	SecurityTeam securityTeam(&medicalTeam, &securityBuilding);
	FacilitiesTeam facilitiesTeam(&securityTeam, &facilities);
	Team& outerTeam = facilitiesTeam;

	FireEmergencyFactory fireEmergencyFactory;
	AllClearFactory allClearFactory;

	// Command: fire. A team evacuates its building and the mediator makes the
	//                                              other buildings evacuate too
	Command *fireEmergency = fireEmergencyFactory.create(outerTeam);
	fireEmergency->solve();
	delete fireEmergency;

	// Command: all clear. Teams return and the mediator restores the buildings
	std::cout << "--- Incident resolved ---" << std::endl;
	Command *allClear = allClearFactory.create(outerTeam);
	allClear->solve();
	delete allClear;
}

void WorkFlow::medicalEmergency()
{
	std::cout << "\n===== Medical emergency =====" << std::endl;

	BasicTeam basicTeam;
	MedicalBuilding medicalBuilding;
	MedicalTeam medicalTeam(&basicTeam, &medicalBuilding);
	MedicalEmergencyFactory medicalEmergencyFactory;
	Team& outerTeam = medicalTeam;
	Command *medicalEmergency = medicalEmergencyFactory.create(outerTeam);
	medicalEmergency->solve();
	delete medicalEmergency;
}

void WorkFlow::securityBreach()
{
	std::cout << "\n===== Security breach =====" << std::endl;

	SecurityBuilding securityBuilding;
	MedicalBuilding medicalBuilding;
	Facilities facilities;
	EmergencyCoordinator coordinator(securityBuilding, medicalBuilding, facilities);

	// Only a security team responds to a breach
	BasicTeam basicTeam;
	SecurityTeam securityTeam(&basicTeam, &securityBuilding);
	Team& outerTeam = securityTeam;

	// Adapter: the clean lock()/unlock() interface over the building's legacy toggleLocked()
	BuildingAdapterImpl accessControl(securityBuilding);

	SecurityBreachFactory securityBreachFactory;
	AllClearFactory allClearFactory;

	Command *securityBreach = securityBreachFactory.create(outerTeam);
	securityBreach->solve();
	delete securityBreach;

	accessControl.lock();
	std::cout << "SecurityBuilding locked: " << securityBuilding.getLocked() << std::endl;

	// Invalid/redundant operation: locking an already locked building is
	// reported and leaves the state unchanged (no second toggle)
	std::cout << "Second lock request on the same building:" << std::endl;
	accessControl.lock();
	std::cout << "SecurityBuilding locked: " << securityBuilding.getLocked() << std::endl;

	std::cout << "--- Threat neutralised ---" << std::endl;
	Command *allClear = allClearFactory.create(outerTeam);
	allClear->solve();
	delete allClear;

	accessControl.unlock();
	std::cout << "SecurityBuilding locked: " << securityBuilding.getLocked() << std::endl;
}
