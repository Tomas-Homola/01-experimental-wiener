#pragma once

#define EPSILON 0.000000001
#define PI 3.14159265358979323846

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

class WienerProcess
{
private:

public:
	unsigned int timeAxisTicks = 0; // pocet bodov na casovej osi
	double* timeAxis = nullptr; // pole na ukladanie hodnot pre jednotlive casy

	unsigned int trajectoriesCount = 0; // pocet trajektorii
	double** trajectories = nullptr; // pole, kde su ulozene jednotlive trajektorie

	WienerProcess(double timeEndValue, unsigned int timeAxisTicks, unsigned int trajectoriesCount);
	~WienerProcess();

	double* computeTrajectory();
	void computeTrajectories();

	double getStartTime() { return this->timeAxis[0]; }
	double getEndTime() { return this->timeAxis[timeAxisTicks - 1]; }

	bool exportData(std::string fileName);
	void printData();
};

double* linspace(double startValue, double endValue, int n); // funkcia na vytvorenie delenia casovej osi, inspirovane funkciou "linspace" z Matlabu
double normalDistribution(double mean, double dispersion); // funkcia na generovanie cisel z normalneho rozdelenia N(mean, dispersion), pouzity Box-Muller Transform, zdroj: https://www.youtube.com/watch?v=EXsdT91XFAY&t=194s
bool exportTrajectory(std::string fileName, double* timeAxis, double* trajectory, unsigned int length);