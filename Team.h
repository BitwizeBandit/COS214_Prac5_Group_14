#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include "IncidentType.h"
#include "Building.h"
#include "SecurityBuilding.h"
#include "MedicalBuilding.h"
#include "Facilities.h"

using namespace std;

class Team
{
	protected:
		bool deployed = false;
	public:
		virtual ~Team() = default;
		virtual void dispatch(IncidentType) = 0;
		virtual void allClear() = 0;
		virtual bool isDeployed() { return deployed; }
};

class BasicTeam : public Team
{
	public:
		virtual void dispatch(IncidentType) {}
		virtual void allClear() {}
};

class Decorator : public Team
{
	protected:
		Team* team;
	public:
		Decorator(Team* team) : team(team) {}
};

class SecurityTeam : public Decorator
{
	private:
		SecurityBuilding* building;
	public:
		void dispatch(IncidentType incidentType)
		{
			if (incidentType == FIRE || incidentType == SECURITY)
			{
				cout << "Security team dispatched" << endl;
				deployed = true;
				building->evacuate();
			}
			team->dispatch(incidentType);
		}
		void allClear()
		{
			if (deployed)
				cout << "Security team returned" << endl;
			team->allClear();	// always pass the allclear down the chain
			if (deployed)
			{
				building->allClear();
				deployed = false;
			}
		}
		SecurityTeam(Team* team, SecurityBuilding* building)
			: Decorator(team), building(building) {}
};

class MedicalTeam : public Decorator
{
	private:
		MedicalBuilding* building;
	public:
		void dispatch(IncidentType incidentType)
		{
			if (incidentType == MEDICAL || incidentType == FIRE)
			{
				cout << "Medical team deployed" << endl;
				deployed = true;
			}
			if (incidentType == FIRE)
				building->evacuate();
			team->dispatch(incidentType);
		}
		void allClear()
		{
			if (deployed)
				cout << "Medical team returned" << endl;
			team->allClear();	// always pass the all-clear down the chain
			if (deployed)
			{
				building->allClear();
				deployed = false;
			}
		}
		MedicalTeam(Team* team, MedicalBuilding* building)
			: Decorator(team), building(building) {}
};

class FacilitiesTeam : public Decorator
{
	private:
		Facilities* building;
	public:
		void dispatch(IncidentType incidentType)
		{
			if (incidentType == FIRE)
			{
				cout << "Facilities team dispatched" << endl;
				deployed = true;
				building->evacuate();
			}
			team->dispatch(incidentType);
		}
		void allClear()
		{
			if (deployed)
				cout << "Facilities team returned" << endl;
			team->allClear();	// always pass the all-clear down the chain
			if (deployed)
			{
				building->allClear();
				deployed = false;
			}
		}
		FacilitiesTeam(Team* team, Facilities* building)
			: Decorator(team), building(building) {}
};

#endif
