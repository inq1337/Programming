﻿#include <iostream>
using namespace std;

double BMI(double weight, double height)
{
	return weight / (height * height / 10000);
}

void printBMI(double BMI)
{
	if (BMI < 18.5)
		cout << "Underweight";
	else if ((18.5 <= BMI) and (BMI < 25))
		cout << "Normal";
	else if ((25 <= BMI) and (BMI < 30))
		cout << "Overweight";
	else
		cout << "Obesity";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double w, h;
	cout << "Введите вес (в килограммах) и рост (в сантиметрах) человека через пробел\n";
	cin >> w >> h;
	printBMI(BMI(w, h));
}