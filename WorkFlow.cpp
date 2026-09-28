#include "WorkFlow.h"
#include "Team.h"
#include "Command.h"
#include "FireEmergency.h"
#include "FireEmergencyFactory.h"
#include "MedicalEmergencyFactory.h"
#include "Facilities.h"
#include "MedicalBuilding.h"

void WorkFlow::fireDrill()
{
	BasicTeam basicTeam;
        MedicalBuilding medicalBuilding;
        MedicalTeam medicalTeam(&basicTeam, &medicalBuilding);
        SecurityBuilding securityBuilding;
        SecurityTeam securityTeam(&medicalTeam, &securityBuilding);
	Facilities facilities;
	FacilitiesTeam facilitiesTeam(&securityTeam, &facilities);
	FireEmergencyFactory fireEmergencyFactory;
	Team& outerTeam = facilitiesTeam;
	Command *fireEmergency = fireEmergencyFactory.create(outerTeam);
	fireEmergency->solve();
	delete fireEmergency;
}

void WorkFlow::medicalEmergency()
{
	BasicTeam basicTeam;
        MedicalBuilding medicalBuilding;
        MedicalTeam medicalTeam(&basicTeam, &medicalBuilding);
        MedicalEmergencyFactory medicalEmergencyFactory;
        Team& outerTeam = medicalTeam;
        Command *medicalEmergency = medicalEmergencyFactory.create(outerTeam);
        medicalEmergency->solve();
        delete medicalEmergency;
}
