#ifndef MEDICAL_BUILDING_H
#define MEDICAL_BUILDING_H
 
#include "Building.h"

// ConcreteColleague
class MedicalBuilding : public Building 
{
    protected:
        void doEvacuate() override;
    
    public:
        MedicalBuilding();
};
 
#endif // MEDICAL_BUILDING_H