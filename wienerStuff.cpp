#include "wienerStuff.h"

WienerProcess::WienerProcess(double timeEndValue, unsigned int timeAxisDivision, unsigned int trajectoriesCount)
{
	//std::cout << "wiener constructor\n";
	this->timeAxis = WienerStuff::linspace(0.0, timeEndValue, timeAxisDivision);
	this->trajectories = new double*[trajectoriesCount];
	for (size_t i = 0; i < trajectoriesCount; i++)
	{
		this->trajectories[i] = new double[timeAixsDivision];
	}
	this->timeAixsDivision = timeAxisDivision;
	this->trajectoriesCount = trajectoriesCount;
}

WienerProcess::~WienerProcess()
{
	//std::cout << "wiener destructor\n";
	delete[] this->timeAxis;
	for (size_t i = 0; i < this->trajectoriesCount; i++)
	{
		delete[] this->trajectories[i];
	}
	delete[] trajectories;
}

double* WienerProcess::computeTrajectory()
{
	return nullptr;
}

void WienerProcess::computeTrajectories()
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
