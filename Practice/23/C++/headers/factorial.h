#pragma once

int factorial(int n)
{
	int fc = 1;
	for (int i = 1; i <= n; i++)
		fc = fc * i;
	return fc;
}