#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b, c;
	cout << "Введите число a и число b\n";
	cin >> a >> b;
	cout << "Производится обмен значениями между a и b\n";
	c = a;
	a = b;
	b = c;
	cout << "Число a = " << a << endl << "Число b = " << b << endl;
	double a1, b1;
	cout << "Введите число a и число b\n";
	cin >> a1 >> b1;
	cout << "Производится обмен значениями между a и b\n";
	a1 = a1 + b1;
	b1 = a1 - b1;
	a1 = a1 - b1;
	cout << "Число a = " << a1 << endl << "Число b = " << b1;
}