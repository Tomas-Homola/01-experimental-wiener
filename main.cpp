#include "wienerStuff.h"

using std::cout;
using std::endl;

int main()
{
	srand(time(0));
	double endTime = 3.0;
	int n = 100, division = 601; // n -> pocet trajektorii, division -> pocet tickov na casovej osi
	bool surfPlotData = false; // nepodstatna cast zadania, len som skusal vykreslit "2D graf" Wienerovho procesu
	WienerProcess wp = WienerProcess(endTime, division, n);
	std::string fileName = "data";

	for (size_t i = 0; i < 3; i++)
	{
		wp.computeTrajectories();
		
		fileName += std::to_string(n);
		cout << "export " << fileName + ".csv" << " started ... ";
		if (wp.exportData(fileName))
			cout << fileName << " exported\n";
		else
			cout << "NOT exported\n";
	
		n *= 10;
		if (n > 10000)
			break;
		wp.reset(endTime, division, n);
		fileName = "data";
	}

	if (surfPlotData)
	{
		wp.reset(endTime, 31, 20);
		wp.computeTrajectories();
		if (wp.exportData("surfPlotTest"))
			cout << "surfPlotTest data exported\n";
		else
			cout << "surfPlotTest data NOT exported\n";
	}

	cout << "\nTask failed successfully\n";
	return 0;
}