#include "wienerStuff.h"

using std::cout;
using std::endl;

int main()
{
	int n = 11;
	double* temp = WienerStuff::linspace(0.0, 1.0, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << temp[i] << endl;
	}

	delete[] temp;
	return 0;
}