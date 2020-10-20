#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double a1, b1, c;
	cout << "Введите число a и число b\n";
	cin >> a1 >> b1;
	cout << "Производится обмен значениями между a и b\n";
	c = a1;
	a1 = b1;
	b1 = c;
	cout << "Число a = " << a1 << endl << "Число b = " << b1 << endl;
	double a2, b2;
	cout << "Введите число a и число b\n";
	cin >> a2 >> b2;
	cout << "Производится обмен значениями между a и b\n";
	a2 = a2 + b2;
	b2 = a2 - b2;
	a2 = a2 - b2;
	cout << "Число a = " << a2 << endl << "Число b = " << b2;
}