#include "SecurityBuilding.h"
#include <iostream>

SecurityBuilding::SecurityBuilding(): Building() {}

void SecurityBuilding::doEvacuate()
{
    occupied = false;
    std::cout << "SecurityBuilding: evacuating security personnel." << std::endl;
}