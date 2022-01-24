#pragma once
#include <iostream>
#include <math.h>

class WienerTrajectory
{
private:
	double* timeAxis = nullptr;
	double* functionValues = nullptr;
	unsigned int division = 0;

public:
	WienerTrajectory(double endValue, unsigned int division);
	~WienerTrajectory();

	void computeTrajectory();
	void newTimeAxis(double newEndValue, unsigned int newDivision)
};

namespace WienerStuff
{
	double* linspace(double startValue, double endValue, int n); // funkcia na vytvorenie delenia casovej osi, inspirovane funkciou linspace z Matlabu
	double normalDistribution(double mean, double dispersion); // funkcia na generovanie cisel z normalneho rozdelenia
}