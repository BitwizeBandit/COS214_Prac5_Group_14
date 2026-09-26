#include "BuildingAdapterImpl.h"
 
BuildingAdapterImpl::BuildingAdapterImpl(Building& building) : building(building) {}
 
void BuildingAdapterImpl::lock() 
{
    if(!building.getLocked()) 
    {
        building.toggleLocked();
    }
}
 
void BuildingAdapterImpl::unlock() 
{
    if(building.getLocked()) 
    {
        building.toggleLocked();
    }
}
 
BuildingAdapterImpl::~BuildingAdapterImpl() {}
 