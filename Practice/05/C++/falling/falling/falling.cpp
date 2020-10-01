#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const double g = 9.8;
	double a, v0, x0, t, x_t;
	a = g;
	cout << "Введите t, v0 и x0\n";
	cin >> t >> v0 >> x0;
	x_t = x0 + v0 * t - a * t * t / 2; //1/2 воспринимается как int, поэтому 1/2=0
	cout << abs(x_t - x0);
}