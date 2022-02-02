#include "wienerStuff.h"

using std::cout;
using std::endl;

int main()
{
	srand(time(0));
	double endTime = 3.0;
	int n = 100, division = 301;
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

	cout << "Task failed successfully\n";
	return 0;
}