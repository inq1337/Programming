#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char sign;
	double num_1, num_2;
	cout << "Введите выражение\n";
	cin >> num_1 >> sign >> num_2;
	switch (sign)
	{
	case '+':
		cout << num_1 + num_2 << endl;
		break;
	case '-':
		cout << num_1 - num_2 << endl;
		break;
	case '*':
		cout << num_1 * num_2 << endl;
		break;
	case '/':
		if (num_2 != 0)
			cout << num_1 / num_2 << endl;
		else
		{
			cout << "Делить на 0 нельзя\n";
			return main();
		}
	default:
		cout << "Вы ввели неверное значение, попробуйте ещё раз\n\n";
		return main();
	}
}