#ifndef BUILDING_H
#define BUILDING_H

class Building
{
	public:
		virtual void evacuate() = 0;
		virtual void allClear() = 0;
};

class SecurityBuilding : public Building
{
	public:
		void evacuate() override {};
		void allClear() override {};
};

class MedicalBuilding : public Building
{
	public:
		void evacuate() override {};
		void allClear() override {};
};

class FacilitiesBuilding : public Building
{
	public:
		void evacuate() override {};
		void allClear() override {};
};

#endif
