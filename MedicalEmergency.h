#ifndef MEDICALEMERGENCY_H
#define MEDICALEMERGENCY_H

#include "Command.h"

class MedicalEmergency : public Command
{
public:
    // MedicalEmergency(Team& team);
    ~MedicalEmergency() override = default;
    void solve() override;
};

#endif