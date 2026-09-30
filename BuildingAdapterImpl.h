
#ifndef BUILDING_ADAPTER_IMPL_H
#define BUILDING_ADAPTER_IMPL_H
 
#include "BuildingAdapter.h"
#include "Building.h"
 
// Object Adapter: wraps a Building& (the Adaptee) by composition and
// translates its legacy toggleLocked() into idempotent lock()/unlock()
class BuildingAdapterImpl : public BuildingAdapter 
{
        Building& building;
    
    public:
        explicit BuildingAdapterImpl(Building& building);
    
        void lock() override;
        void unlock() override;
    
        ~BuildingAdapterImpl() override;
};
 
#endif // BUILDING_ADAPTER_IMPL_H