#include <iostream>
#include <iomanip>
#include "factorial.h"
#include "sinus.h"

int main()
{
	using std::cout;
	using std::endl;

	cout << "n\t" << "n!" <<endl;
	for (int n = 1; n <= 10; n++)
		cout << n << "\t" << factorial(n) << endl;
	cout << endl << "x\t" << "sin(x)" << endl;
	for (double x = 0; x <= 3.1415 / 4; x = x + 3.1415 / 180)
		cout << std::setprecision(4) << x << "\t" << sin(x, 5) << endl;
	cout << endl;
}