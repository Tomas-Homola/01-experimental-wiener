#include "wienerStuff.h"

WienerProcess::WienerProcess(double timeEndValue, unsigned int timeAxisTicks, unsigned int trajectoriesCount)
{
	//std::cout << "wiener constructor\n";
	this->timeAxisTicks = timeAxisTicks; // delenie casovej osi
	this->trajectoriesCount = trajectoriesCount; // pocet trajektorii
	
	this->timeAxis = linspace(0.0, timeEndValue, timeAxisTicks); // vytvorenie casovej osi
	this->trajectories = new double*[trajectoriesCount]; // alokacia pamati pre trajektorie

	for (size_t i = 0; i < trajectoriesCount; i++)
	{
		//this->trajectories[i] = new double[timeAxisTicks]; // alokacia pamati pre jednotlive trajektorie
		this->trajectories[i] = (double*)calloc(timeAxisTicks, sizeof(double));
	}
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
	double* trajectory = new double[timeAxisTicks];
	trajectory[0] = normalDistribution(0.0, timeAxis[0] - 0.0);

	for (size_t i = 1; i < timeAxisTicks; i++)
	{
		trajectory[i] = trajectory[i - 1] + normalDistribution(0.0, timeAxis[i] - timeAxis[i - 1]);
	}

	return trajectory;
}

void WienerProcess::computeTrajectories()
{
	for (size_t i = 0; i < trajectoriesCount; i++)
	{
		trajectories[i][0] = normalDistribution(0.0, timeAxis[0] - 0.0);
		for (size_t j = 1; j < timeAxisTicks; j++)
		{
			trajectories[i][j] = trajectories[i][j - 1] + normalDistribution(0.0, timeAxis[j] - timeAxis[j - 1]);
		}
		//std::cout << i << "done\n";
	}
	std::cout << "computing trajectories done\n";
}

bool WienerProcess::exportData(std::string fileName)
{
	fileName += ".csv";
	std::ofstream exportFile(fileName);
	if (!exportFile.is_open())
		return false;

	for (size_t i = 0; i < timeAxisTicks; i++)
	{
		exportFile << timeAxis[i] << ";";
	}
	
	exportFile << "\n";
	
	for (size_t i = 0; i < trajectoriesCount; i++)
	{
		for (size_t j = 0; j < timeAxisTicks; j++)
		{
			exportFile << trajectories[i][j] << ";";
		}
		exportFile << "\n";
	}

	exportFile.close();
	return true;
}

void WienerProcess::printData()
{
	for (size_t i = 0; i < timeAxisTicks; i++)
	{
		std::cout << timeAxis[i] << ",";
	}

	std::cout << "\n";

	for (size_t i = 0; i < trajectoriesCount; i++)
	{
		for (size_t j = 0; j < timeAxisTicks; j++)
		{
			std::cout << trajectories[i][j] << ",";
		}
		std::cout << "\n";
	}
}

double* linspace(double startValue, double endValue, int n)
{
	double* temp = new double[n];
	double deltaX = (endValue - startValue) / (n - 1);

	for (size_t i = 0; i < n; i++)
	{
		temp[i] = i * deltaX;
	}
	
	return temp;
}

double normalDistribution(double mean, double dispersion)
{
	// dve nahodne cisla rovnomerne rozdelene z intervalu [0,1]
	double U1 = (double)rand() / RAND_MAX;
	double U2 = (double)rand() / RAND_MAX;
	
	if (U1 < EPSILON) // kontrola kvoli definicnemu oboru prirodzeneho logaritmu
		return 0.0;
	else
		return (mean + dispersion * sqrt(-2.0 * log(U1)) * cos(2 * PI * U2));
}

bool exportTrajectory(std::string fileName, double* timeAxis, double* trajectory, unsigned int length)
{
	fileName += ".csv";
	std::ofstream exportFile(fileName);
	if (!exportFile.is_open())
		return false;

	for (size_t i = 0; i < length; i++)
	{
		exportFile << timeAxis[i] << ",";
	}

	exportFile << "\n";

	for (size_t i = 0; i < length; i++)
	{
		exportFile << trajectory[i] << ",";
	}

	exportFile.close();
	return true;
}
