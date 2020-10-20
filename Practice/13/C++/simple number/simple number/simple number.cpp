#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long num;
	int cnt, i = 0;
	cout << "Введите число\n";
	cin >> num;
	if (num >= 2)
	{
		for (cnt = 2; cnt <= floor(sqrt(num)); cnt++)
		{
			if (num % cnt == 0)
				i++;
		}
		if (i > 0)
			cout << "Составное";
		else
			cout << "Простое";
	}
	else
	{
		cout << "Вы ввели некорректные данные. Попробуйте ещё раз\n\n";
		return main();
	}
}