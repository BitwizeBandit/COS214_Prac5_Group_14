#include <iostream>
#include "Team.h"
#include "EmergencyCoordinator.h"
#include "FireEmergencyFactory.h"
#include "MedicalEmergencyFactory.h"
#include "SecurityBreachFactory.h"
#include "AllClearFactory.h"

int main()
{
	// Buildings and mediator (stack allocted, our client owns them)
	SecurityBuilding securityBuilding;
	MedicalBuilding medicalBuilding;
	Facilities facilities;
	EmergencyCoordinator coordinator(securityBuilding, medicalBuilding, facilities);

	// Decorator stack, Team.h keeps its raw pointers
	BasicTeam basicTeam;
	FacilitiesTeam facilitiesTeam(&basicTeam, &facilities);
	MedicalTeam medicalTeam(&facilitiesTeam, &medicalBuilding);
	SecurityTeam securityTeam(&medicalTeam, &securityBuilding);

	// The outermost decorator is passed to the factories as a Team&
	// Polymorphism still works through the Reference: dispatch() runs SecurityTeam::dispatch, which walks down 
	// 																the Decorator chain
	Team& team = securityTeam;

	FireEmergencyFactory fireFactory;
	SecurityBreachFactory breachFactory;
	AllClearFactory allClearFactory;

	std::cout << "=== Fire ===" << std::endl;
	Command* fire = fireFactory.create(team);   // Factory::create(Team&) 
	fire->solve();
	delete fire;

	std::cout << "\n=== All clear ===" << std::endl;
	Command* clear = allClearFactory.create(team);
	clear->solve();
	delete clear;

	std::cout << "\n=== Security breach ===" << std::endl;
	Command* breach = breachFactory.create(team);
	breach->solve();
	delete breach;

	return 0;
}
