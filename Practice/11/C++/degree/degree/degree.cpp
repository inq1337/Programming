#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double defnum, num;
	int deg, cnt;
	cout << "Введите число и степень, в которую его нужно возвести\n";
	cin >> defnum;
	cin >> deg;
	num = defnum;
	if (deg == 0)
		cout << 1;
	else if (deg < 0)
	{
		deg = -deg;
		for (cnt = 1; cnt < deg; cnt = cnt + 1)
			num = num * defnum;
		cout << 1 / num;
	}
	else
	{
		for (cnt = 1; cnt < deg; cnt = cnt + 1)
			num = num * defnum;
		cout << num;
	}
}