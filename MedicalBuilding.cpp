#include "MedicalBuilding.h"
#include <iostream>

MedicalBuilding::MedicalBuilding(): Building() {}

void MedicalBuilding::doEvacuate()
{
    occupied = false;
    std::cout << "MedicalBuilding: evacuating patients and medical staff." << std::endl;
}

void MedicalBuilding::doAllClear() 
{
    occupied = true;
    std::cout << "MedicalBuilding: all clear, resuming normal operations." << std::endl;
}