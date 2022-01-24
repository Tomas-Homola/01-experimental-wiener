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
	return 0.0;
}
