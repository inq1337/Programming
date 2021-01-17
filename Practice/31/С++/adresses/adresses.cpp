#include <iostream>
#include <vector>
#include <fstream>

using std::endl;
using std::vector;
using std::ostream;

#define PART 2

#if PART == 3
ostream& operator<< (ostream& out, vector<int> vector)
{
	out << vector.size() << "\t| ";
	for (auto& item : vector)
	{
		out << &item << " ";
	}
	out << endl;
	return out;
}
#elif PART == 2
ostream& operator<< (ostream& out, const vector<int> &vector)
{
	out << vector.size() << "\t| ";
	for (auto& item : vector)
	{
		out << &item << " ";
	}
	out << endl;
	return out;
}
#endif

int main()
{
	srand(time(nullptr));
	vector<int> vector;
	std::ofstream data("data.txt");

	for (int i = 0; i < 64; ++i)
	{
		vector.push_back(rand());
		data << vector;
	}
	for (int i = 0; i < 63; ++i)
	{
		vector.pop_back();
		data << vector;
	}

	data.close();
}

/*
1.
При передаче по ссылке не создаётся копия вектора.
Адреса первых элементов всегда разные, потому что вектор копируется в новый
участок памяти (старый очищается) при добавлении нового элемента, если возможность
расположить элементы последовтально отсутствуют. Поэтому адреса изменяются.

2.
Скорее нельзя, чем можно. Это зависит от того, был ли вектор перемещён
в новый участок памяти. А он, скорее всего, был перемещён, т.к. маловероятна
возможность последовательного расположения такого кол-ва элементов

3.
Адреса не изменяются, т.к. идёт удаление  элементов, которые уже расположены последовательно,
а значит, нет нужды копировать вектор в новый участок памяти.

4.
При передаче по значению при по попадании в функцию каждый раз создаётся новый вектор,
поэтому адреса разные и при удалении.
*/