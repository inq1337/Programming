#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void ArrayOuter(vector<int> arr)
{
	for (auto item : arr)
	{
		cout << item << " ";
	}
	cout << endl;
}

vector<int> BozoSort(vector<int> arr, bool order = true)
{
	bool sorted = false;
	int n = arr.size();

	while (!sorted)
	{
		if (order)
		{
			int index1 = rand() % n;
			int index2 = rand() % n;

			int temp = arr[index1];
			arr[index1] = arr[index2];
			arr[index2] = temp;

			sorted = true;

			for (int i = 1; i < n; i++)
			{
				if (arr[i - 1] > arr[i])
				{
					sorted = false;
					break;
				}
			}
		}
		else
		{
			int index1 = rand() % n;
			int index2 = rand() % n;

			int temp = arr[index1];
			arr[index1] = arr[index2];
			arr[index2] = temp;

			sorted = true;

			for (int i = 1; i < n; i++)
			{
				if (arr[i - 1] < arr[i])
				{
					sorted = false;
					break;
				}
			}
		}
	}

	return arr;
}

vector<int> BozoSort(vector<vector<int>> matrix, bool order = true)
{
	vector<int> arr;
	for (auto &row : matrix)
	{
		for (auto item : row)
		{
			arr.push_back(item);
		}
	}
	return BozoSort(arr, order);
}

vector<int> BozoSort(int a, int b, int c, bool order = true)
{
	vector<int> arr(3);
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	return BozoSort(arr, order);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	int n, s;
	cout << "Введите количество элементов\n";
	cin >> n;
	s = sqrt(n);
	vector<int> arr(n);
	vector<vector<int>> matrix(s, vector<int>(s));

	cout << "Заполните массив\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int i = 0;
	while (i < n)
	{
		for (int j = 0; j < s; j++)
		{
			for (int k = 0; k < s; k++)
			{
				matrix[j][k] = arr[i];
				i++;
			}
		}
	}
	cout << endl;
	ArrayOuter(BozoSort(arr));
	ArrayOuter(BozoSort(arr, false));
	ArrayOuter(BozoSort(matrix));
	ArrayOuter(BozoSort(matrix, false));
	ArrayOuter(BozoSort(arr[0], arr[1], arr[2]));
	ArrayOuter(BozoSort(arr[0], arr[1], arr[2], false));
}