#include <iostream>
#include "BuildingAdapterImpl.h"
 
BuildingAdapterImpl::BuildingAdapterImpl(Building& building) : building(building) {}
 
void BuildingAdapterImpl::lock() 
{
    if(!building.getLocked()) 
    {
        building.toggleLocked();
    }
    else
    {
        // Redundant request: report it instead of silently ignoring it
        std::cout << "Adapter: building is already locked, no action taken." << std::endl;
    }
}
 
void BuildingAdapterImpl::unlock() 
{
    if(building.getLocked()) 
    {
        building.toggleLocked();
    }
    else
    {
        std::cout << "Adapter: building is already unlocked, no action taken." << std::endl;
    }
}
 
BuildingAdapterImpl::~BuildingAdapterImpl() {}
