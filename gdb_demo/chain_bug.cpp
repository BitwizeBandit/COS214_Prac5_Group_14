// Historical reproduction of the allClear() chain bug (see gdb_demo/README.txt)
// gdb_demo/Team.h is the ORIGINAL Team.h from commit 8fce590, kept only so the
// bug can be reproduced under GDB. The fixed version is outsid ethis folder ../Team.h.
#include "Team.h"
#include "EmergencyCoordinator.h"

int main()
{
	SecurityBuilding securityBuilding;
	MedicalBuilding medicalBuilding;
	Facilities facilities;
	EmergencyCoordinator coordinator(securityBuilding, medicalBuilding, facilities);

	BasicTeam basicTeam;
	MedicalTeam medicalTeam(&basicTeam, &medicalBuilding);
	SecurityTeam securityTeam(&medicalTeam, &securityBuilding);

	securityTeam.dispatch(MEDICAL);   // only the MedicalTeam deploys
	std::cout << "medical deployed after dispatch: " << medicalTeam.isDeployed() << std::endl;

	securityTeam.allClear();          // should release the MedicalTeam too
	std::cout << "medical deployed after allClear:  " << medicalTeam.isDeployed() << std::endl;
	return medicalTeam.isDeployed() ? 1 : 0;
}
