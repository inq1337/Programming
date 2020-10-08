#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b, c, D;
    cout << "Введите коэффициенты уравнения a, b и c\n";
    cin >> a >> b >> c;
    if (a != 0)
    {
        if (c != 0 or b != 0)
        {
            D = b * b - 4 * a * c;
            if (D > 0)
            {
                cout << "x1 = " << (-b + sqrt(D) / (2 * a)) << endl;
                cout << "x1 = " << (-b - sqrt(D) / (2 * a)) << endl;
            }
            else if (D == 0)
                cout << "x = " << -b / 2 * a;
            else
                cout << "Нет корней";
        }
        else
            cout << "x = 0";
    }
    else
        if (b == 0 and c != 0)
            cout << "Это не уравнение";
        else if (c == 0 and b != 0)
            cout << "x = " << 0;
        else if (b == 0 and c == 0)
            cout << "Корнем уравнения является любое число";
        else
            cout << "x = " << -c / b;
}