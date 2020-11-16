#include <iostream>
#include <iomanip>
#include "factorial.h"
#include "sinus.h"
#include "combination.h"

int main()
{
	using std::cout;
	using std::endl;

	cout << "n\t" << "n!" <<endl;
	for (int n = 1; n <= 10; n++)
	{
		cout << n << "\t" << factorial(n) << endl;
	}
	cout << endl << "x\t" << "sin(x)" << endl;
	float pi = 3.141592;
	for (double x = 0; x <= pi / 4; x = x + pi / 180)
	{
		cout << std::setprecision(4) << x << "\t" << sin(x, 5) << endl;
	}
	cout << endl << "k\t" << "C(k, 10)" << endl;
	for (int k = 1; k <= 10; k++)
	{
		cout << k << "\t" << comb(k, 10) << endl;
	}
}