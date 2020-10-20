#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long x = 1, n;
	int cnt = 0;
	cout << "Введите число n >= 0\n";
	cin >> n;
	if (n >= 0)
	{
		while (x <= n)
		{
			x = x * 2;
			cnt++;
		}
		cout << cnt;
	}
	else
	{
		cout << "Вы ввели некорректные данные. Попробуйте ещё раз\n\n";
		return main();
	}
}