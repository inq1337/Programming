#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b, c, D, x1, x2;
	cout << "Введите коэффициенты уравнения a, b и c\n";
	cin >> a;
	cin >> b;
	cin >> c;
	if (a == 0 and b == 0 and c == 0)
		cout << "Корнем уравнения является любое число\n";
	else if (a == 0 and b != 0 and c == 0)
		cout << "Корень уравнения равен нулю\n";
	else if (a != 0 and b == 0 and c == 0)
		cout << "Корень уравнения равен нулю\n";
	else if (a < 0 and b == 0 and c < 0)
		cout << "Корней нет\n";
	else if (a == 0 and b != 0 and c != 0)
	{
		x1 = b / -c;
		cout << "Уравнение имеет один корень\n";
		cout << "x1 = " << x1;
	}
	else if (a != 0 and b != 0 and c == 0)
	{
		x1 = 0;
		x2 = -b / a;
		cout << "Уравнение имеет следующие корни:\n" << "x1 = " << x1 << endl << "x2 = " << x2;
	}
	else if (a != 0 and b == 0 and c < 0)
	{
		x1 = sqrt(-c / a);
		x2 = -sqrt(-c / a);
		cout << "Уравнение имеет следующие корни:\n" << "x1 = " << x1 << endl << "x2 = " << x2;
	}
	else if (a != 0 and b != 0 and c != 0)
	{
		D = b * b - 4 * a * c;
		if (D >= 0)
		{
			if (D == 0)
			{
				x1 = -b / 2 * a;
				cout << "Уравнение имеет один корень\n";
				cout << "x1 = " << x1;
			}
			else
			{
				x1 = -b + sqrt(D) / 2 * a;
				x2 = -b - sqrt(D) / 2 * a;
				cout << "Уравнение имеет следующие корни:\n" << "x1 = " << x1 << endl << "x2 = " << x2;
			}

		}
		else
		{
			cout << "Дискриминант отрицательный, уравнение не имеет действительных корней. Введите другие коэффициенты\n\n";
			return main();
		}
	}
	else
	{
		cout << "Вы ввели некорректные значения. Решений нет. Попробуйте ещё раз\n\n";
		return main();
	}
}