#include "Facilities.h"
#include <iostream>

Facilities::Facilities(): Building() {}

void Facilities::doEvacuate()
{
    occupied = false;
    std::cout << "Facilities: shutting down non-essential systems and clearing staff." << std::endl;
}

void Facilities::doAllClear() 
{
    occupied = true;
    std::cout << "Facilities: restoring systems and recalling staff." << std::endl;
}