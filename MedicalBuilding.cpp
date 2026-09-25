#include "MedicalBuilding.h"
#include <iostream>

MedicalBuilding::MedicalBuilding(): Building() {}

void MedicalBuilding::doEvacuate()
{
    occupied = false;
    std::cout << "MedicalBuilding: evacuating patients and medical staff." << std::endl;
}