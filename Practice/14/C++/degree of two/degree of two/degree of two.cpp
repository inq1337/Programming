#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	long long x, n;
	int cnt;
	cout << "Введите число n >= 0\n";
	cin >> n;
	x = 1;
	cnt = 0;
	if (n >= 0)
	{
		if (n > 0)
		{
			while (x <= n)
			{
				x = x * 2;
				cnt++;
			}
			cout << cnt;
		}
		else
			cout << cnt;
	}
	else
	{
		cout << "Вы ввели некорректные данные. Попробуйте ещё раз\n\n";
		return main();
	}
}