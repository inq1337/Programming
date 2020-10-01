#include <iostream>
using namespace std;

int main() {
	int int_1, int_2;
	double db_1, db_2;
	int_1 = 3;
	int_2 = 3.14;	//Выводится 3, потому что 'int' воспринимает только целую часть
	db_1 = 3;	//Всё нормально, потому что 'double' воспринимает 3, как 3.0
	db_2 = 3.14;
	cout << int_1 << endl << int_2 << endl << db_1 << endl << db_2;
}