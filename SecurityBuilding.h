#ifndef SECURITY_BUILDING_H
#define SECURITY_BUILDING_H

#include "Building.h"
 
// ConcreteColleague
class SecurityBuilding : public Building 
{
    protected:
        void doEvacuate() override;
    
    public:
        SecurityBuilding();
};

#endif // SECURITY_BUILDING_H