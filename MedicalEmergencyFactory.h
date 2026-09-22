#ifndef MEDICALEMERGENCYFACTORY_H
#define MEDICALEMERGENCYFACTORY_H

#include "Factory.h"
#include "MedicalEmergency.h"

class MedicalEmergencyFactory : public Factory {
public:
    ~MedicalEmergencyFactory() override = default;
    // Command* create(Team& team) override;
};

#endif