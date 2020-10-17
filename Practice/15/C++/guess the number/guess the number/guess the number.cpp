#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	short x, ig, restart, cnt;
	cout << "Вас приветствует игра \"Угадай число\"\n";
	cout << "Загадано целое число от 0 до 100\n";
	while (true)
	{
		x = rand() % 100;
		cout << "Попробуйте угадать. У вас есть 5 попыток. Введите число\n";
		for (cnt = 0; cnt < 5; cnt++)
		{
			cin >> ig;
			if (ig > x and cnt < 4)
				cout << "Загаданное число меньше\n";
			else if (ig < x and cnt < 4)
				cout << "Загаданное число больше\n";
			else if (ig == x)
			{
				cout << "Поздравляю! Вы угадали\n";
				break;
			}
			else if (ig != x and cnt == 4)
				cout << "Вы проиграли. Было загадано: " << x << endl;
		}
		cout << "Хотите начать сначала? (1 - ДА)\n";
		cin >> restart;
		if (restart != 1)
			break;
	}
}