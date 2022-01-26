#pragma once

#define _USE_MATH_DEFINES
#define EPSILON 0.000000001

#include <iostream>
#include <cmath>

class WienerProcess
{
private:

public:
	unsigned int timeAixsDivision = 0; // pocet bodov na casovej osi
	double* timeAxis = nullptr; // pole na ukladanie hodnot pre jednotlive casy

	unsigned int trajectoriesCount = 0; // pocet trajektorii
	double** trajectories = nullptr; // pole, kde su ulozene jednotlive trajektorie

	WienerProcess(double timeEndValue, unsigned int timeAxisDivision, unsigned int trajectoriesCount);
	~WienerProcess();

	double* computeTrajectory();
	void computeTrajectories();

	double getStartTime() { return 0.0; }
	double getEndTime() { return this->timeAxis[timeAixsDivision - 1]; }
};

namespace WienerStuff
{
	double* linspace(double startValue, double endValue, int n); // funkcia na vytvorenie delenia casovej osi, inspirovane funkciou "linspace" z Matlabu
	double normalDistribution(double mean, double dispersion); // funkcia na generovanie cisel z normalneho rozdelenia N(mean, dispersion), pouzity Box-Muller Transform, zdroj: https://www.youtube.com/watch?v=EXsdT91XFAY&t=194s
}