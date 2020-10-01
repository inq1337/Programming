#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int method;
	double a, b, c, S, p, xA, yA, xB, yB, xC, yC;
	cout << "Выберите способ нахождения площади треугольника\n" << "1 - через длины сторон\n" << "2 - через координаты вершин\n";
	cin >> method;
	switch (method)
	{
	case 1:
		cout << "Введите длины сторон a, b, c\n";
		cin >> a;
		cin >> b;
		cin >> c;
		if (a > 0 and b > 0 and c > 0)
		{
			if (b + c > a and a + c > b and b + a > c)
			{
				p = (a + b + c) / 2;
				S = sqrt(p * (p - a) * (p - b) * (p - c));
				cout << "Площадь треугольника S = " << S;
			}
			else
			{
				cout << "Такого треугольника не существует. Измените параметры\n\n";
			}
		}
		else
		{
			cout << "Вы ввели некорректные значения. Попробуйте ещё раз\n\n";
			return main();
		}
		break;
	case 2:
		cout << "Введите попарно координаты вершин x и y\n";
		cout << "Введите координаты вершины A\n";
		cin >> xA >> yA;
		cout << "\nВведите координаты вершины B\n";
		cin >> xB >> yB;
		cout << "\nВведите координаты вершины C\n";
		cin >> xC >> yC;
		a = sqrt((xC - xB) + (yC - yB));
		b = sqrt((xA - xC) + (yA - yC));
		c = sqrt((xB - xA) + (yB - yA));
		if (a > 0 and b > 0 and c > 0)
		{
			if (b + c > a and a + c > b and b + a > c)
			{
				p = (a + b + c) / 2;
				S = sqrt(p * (p - a) * (p - b) * (p - c));
				cout << "Площадь треугольника S = " << S;
			}
			else
			{
				cout << "Такого треугольника не существует. Измените параметры\n\n";
			}
		}
		else
		{
			cout << "Вы ввели некорректные значения. Попробуйте ещё раз\n\n";
			return main();
		}
		break;
	default: 
		cout << "Неверный ввод. Попробуйте ещё раз\n\n";
		return main();
	}
}