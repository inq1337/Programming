#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long s, l1, l2, r1, r2, x;
	cout << "Введите через пробел числа s, l1, r1, l2, r2\n";
	cout << "Числа должны удовлетворять условиям l1 <= r1 и l2 <= r2\n";
	cin >> s >> l1 >> r1 >> l2 >> r2;
	if (l1 <= r1 and l2 <= r2)
	{
		if (s < l1 + l2 or s > r1 + r2)
			cout << -1;
		else
		{
			if (l1 + r2 - s == 0)
				cout << l1 << " " << r2;
			else if (l1 + r2 - s < 0)
			{
				x = l1 - (l1 + r2 - s);
				cout << x << " " << r2;
			}
			else if (l1 + r2 - s > 0)
			{
				x = r2 - (l1 + r2 - s);
				cout << l1 << " " << x;
			}
		}
	}
	else
	{
		cout << "Числа не удовлетворяют условиям\n";
		return main();
	}
}