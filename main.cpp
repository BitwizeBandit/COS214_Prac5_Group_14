#include "Team.h"

int main()
{
	BasicTeam basicTeam;
	MedicalBuilding medicalBuilding;
	MedicalTeam medicalTeam(&basicTeam, &medicalBuilding);
	SecurityBuilding securityBuilding;
	SecurityTeam securityTeam(&medicalTeam, &securityBuilding);
	securityTeam.dispatch(FIRE);
}


