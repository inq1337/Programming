#ifndef SINUS_H
#define SINUS_H
#include "factorial.h"
#include <cmath>
double sin(double x, int k)
{
	double sinx = x;
	for (int n = 1; n <= k; k++)
		sinx = sinx + pow(-1, n) * (pow(x, (2 * n + 1)) / factorial(2 * n + 1));
	return sinx;
}
#endif