#include "wienerStuff.h"

WienerTrajectory::WienerTrajectory(double endValue, unsigned int division)
{
	this->timeAxis = WienerStuff::linspace(0.0, endValue, division);
	this->functionValues = new double[division];
	this->division = division;
}

WienerTrajectory::~WienerTrajectory()
{
	delete[] this->timeAxis;
	delete[] this->functionValues;
}

void WienerTrajectory::computeTrajectory()
{
}

void WienerTrajectory::newTimeAxis(double newEndValue, unsigned int newDivision)
{
}

double* WienerStuff::linspace(double startValue, double endValue, int n)
{
	double* temp = new double[n];
	double deltaX = (endValue - startValue) / (n - 1);

	for (size_t i = 0; i < n; i++)
	{
		temp[i] = i * deltaX;
	}
	
	return temp;
}

double WienerStuff::normalDistribution(double mean, double dispersion)
{
	// dve nahodne cisla rovnomerne rozdelene z intervalu [0,1]
	double U1 = (double)rand() / RAND_MAX;
	double U2 = (double)rand() / RAND_MAX;
	
	if (U1 < EPSILON) // kontrola kvoli definicnemu oboru prirodzeneho logaritmu
		return 0.0;
	else
		return (mean + dispersion * sqrt(-2.0 * log(U1)) * cos(2 * M_PI * U2));
}
