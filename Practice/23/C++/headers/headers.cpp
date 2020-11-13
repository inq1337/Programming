#include <iostream>
#include "factorial.h"

int main()
{
	using std::cout;
	using std::endl;

	cout << "n\t" << "n!\t" <<endl;
	for (int n = 1; n <= 10; n++)
		cout << n << "\t" << factorial(n) << endl;

}