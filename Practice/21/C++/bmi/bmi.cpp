#include <iostream>
using namespace std;

double BMI(double weight, double height)
{
	return weight / (height * height);
}

void printBMI(double BMI)
{
	if (BMI < 18.5)
		cout << "Underweight\n";
	else if (18.5 <= BMI < 25)
		cout << "Normal weight\n";
	else if (25 <= BMI < 30)
		cout << "Overweight\n";
	else
		cout << "Obesity";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double w, h, bmi;
	cout << "Введите вес (в килограммах) и рост (в метрах) человека через пробел\n";
	cin >> w >> h;
	bmi = BMI(w, h);
	printBMI(bmi);
}