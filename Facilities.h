#ifndef FACILITIES_H
#define FACILITIES_H
 
#include "Building.h"
 
// ConcreteColleague
class Facilities : public Building 
{
    protected:
        void doEvacuate() override;
    
    public:
        Facilities();
};
 
#endif // FACILITIES_H