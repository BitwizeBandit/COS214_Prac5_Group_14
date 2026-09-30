#ifndef BUILDING_ADAPTER_H
#define BUILDING_ADAPTER_H
 
// Target interface: the clean lock()/unlock() contract CampusGuard wants
class BuildingAdapter 
{
    public:
        virtual void lock() = 0;
        virtual void unlock() = 0; // CampusGuard wants to call these

        virtual ~BuildingAdapter();
};
 
#endif // BUILDING_ADAPTER_H