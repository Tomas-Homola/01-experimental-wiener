#include "wienerStuff.h"

using std::cout;
using std::endl;

int main()
{
	srand(time(0));
	int n = 100000;
	int temp[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//double* temp = linspace(0.0, 1.0, n);

	WienerProcess wp = WienerProcess(5.0, 100, 10000);
	wp.computeTrajectories();
	//wp.printData();
	//cout << "\n";
	//for (size_t i = 0; i < wp.timeAxisTicks; i++)
	//{
	//	cout << wp.timeAxis[i] << ":::" << wp.trajectories[0][i] << endl;
	//}
	//cout << endl;

	if (wp.exportData("data10000"))
		cout << "exported\n";
	else
		cout << "NOT exported";
	
	
	//for (size_t i = 0; i < n; i++)
	//{
	//	//cout << temp[i] << endl;
	//	double x = normalDistribution(5.0, 2.0);
	//	
	//	if (x < 0.0001)
	//		temp[0]++;
	//	else if (x > 0.001 && x < 1.001)
	//		temp[1]++;
	//	else if (x > 1.001 && x < 2.001)
	//		temp[2]++;
	//	else if (x > 2.001 && x < 3.001)
	//		temp[3]++;
	//	else if (x > 3.001 && x < 4.001)
	//		temp[4]++;
	//	else if (x > 4.001 && x < 5.001)
	//		temp[5]++;
	//	else if (x > 5.001 && x < 6.001)
	//		temp[6]++;
	//	else if (x > 6.001 && x < 7.001)
	//		temp[7]++;
	//	else if (x > 7.001 && x < 8.001)
	//		temp[8]++;
	//	else if (x > 8.001 && x < 9.001)
	//		temp[9]++;
	//	else if (x > 9.001 && x < 10.001)
	//		temp[10]++;
	//	else if (x > 10.001)
	//		temp[11]++;
	//}
	//
	//for (size_t i = 0; i < 12; i++)
	//{
	//	cout << i << ": ";
	//	int pocet = temp[i] / 500;
	//	temp[i] = 0;
	//	for (size_t j = 0; j < pocet; j++)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}
	//
	//cout << endl << endl;
	//
	//for (size_t i = 0; i < n; i++)
	//{
	//	//cout << temp[i] << endl;
	//	//double x = normalDistribution(5.0, 0.5);
	//	double x = ((double)rand() / RAND_MAX) * 11.0 - 1.0;
	//
	//	if (x < 0.0001)
	//		temp[0]++;
	//	else if (x > 0.001 && x < 1.001)
	//		temp[1]++;
	//	else if (x > 1.001 && x < 2.001)
	//		temp[2]++;
	//	else if (x > 2.001 && x < 3.001)
	//		temp[3]++;
	//	else if (x > 3.001 && x < 4.001)
	//		temp[4]++;
	//	else if (x > 4.001 && x < 5.001)
	//		temp[5]++;
	//	else if (x > 5.001 && x < 6.001)
	//		temp[6]++;
	//	else if (x > 6.001 && x < 7.001)
	//		temp[7]++;
	//	else if (x > 7.001 && x < 8.001)
	//		temp[8]++;
	//	else if (x > 8.001 && x < 9.001)
	//		temp[9]++;
	//	else if (x > 9.001 && x < 10.001)
	//		temp[10]++;
	//	else if (x > 10.001)
	//		temp[11]++;
	//}
	//
	//for (size_t i = 0; i < 12; i++)
	//{
	//	cout << i << ": ";
	//	int pocet = temp[i] / 500;
	//	for (size_t j = 0; j < pocet; j++)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}
	
	//delete[] temp;
	

	return 0;
}