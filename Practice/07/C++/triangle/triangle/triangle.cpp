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
		cin >> a >> b >> c;
		if (a > 0 and b > 0 and c > 0)
		{
			while ((b + c <= a) or (a + c <= b) or (b + a <= c))
			{
				cout << "Такого треугольника не существует. Измените параметры\n\n";
				cin >> a >> b >> c;
			}
			p = (a + b + c) / 2;
			S = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "Площадь треугольника S = " << S;
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
		a = sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB));
		b = sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));
		c = sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
		if (a > 0 and b > 0 and c > 0)
		{
			while ((b + c <= a) or (a + c <= b) or (b + a <= c))
			{
				cout << "Такого треугольника не существует. Измените параметры\n\n";
				cout << "Введите координаты вершины A\n";
				cin >> xA >> yA;
				cout << "\nВведите координаты вершины B\n";
				cin >> xB >> yB;
				cout << "\nВведите координаты вершины C\n";
				cin >> xC >> yC;
				a = sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB));
				b = sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));
				c = sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
			}
			p = (a + b + c) / 2;
			S = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "Площадь треугольника S = " << S;
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