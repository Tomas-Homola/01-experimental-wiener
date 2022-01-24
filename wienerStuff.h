#pragma once

#define _USE_MATH_DEFINES
#define EPSILON 0.000000001

#include <iostream>
#include <cmath>

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
	void newTimeAxis(double newEndValue, unsigned int newDivision);
};

namespace WienerStuff
{
	double* linspace(double startValue, double endValue, int n); // funkcia na vytvorenie delenia casovej osi, inspirovane funkciou linspace z Matlabu
	double normalDistribution(double mean, double dispersion); // funkcia na generovanie cisel z normalneho rozdelenia N(mean, dispersion), pouzity Box-Muller Transform, zdroj: https://www.youtube.com/watch?v=EXsdT91XFAY&t=194s
}