#ifndef COMBINATION_H
#define COMBINATION_H
#include "factorial.h"
int comb(int k, int n)
{
	int C;
	C = factorial(n) / (factorial(k) * factorial(n - k));
	return C;
}
#endif