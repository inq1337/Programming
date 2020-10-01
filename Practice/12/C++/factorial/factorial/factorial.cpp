#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int num, cnt;
	long long fc;
	fc = 1;
	cout << "Введите число, факториал которого необходимо рассчитать\n";
	cin >> num;
	if (num <= 12)
	{
		for (cnt = 1; cnt <= num; cnt++)
		{
			fc = fc * cnt;
		}
		cout << "Факториал числа " << num << " равен " << fc;
	}
	else
	{
		cout << "Входные данные некорректны или вы ввели слишком большое число. Рассчитать факториал невозможно. Попробуйте ещё раз\n\n";
		return main();
	}
}