#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void ArrayOuter(vector<int> arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
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
	int n, s, i;
	s = matrix.size();
	n = pow(s, 2);
	i = 0;
	vector<int> arr(n);
	while (i < n)
	{
		for (int j = 0; j < s; j++)
		{
			for (int k = 0; k < s; k++)
			{
				arr[i] = matrix[j][k];
				i++;
			}
		}
	}
	if (order)
	{
		return BozoSort(arr);
	}
	else
	{
		return BozoSort(arr, false);
	}
}

vector<int> BozoSort(int a, int b, int c, bool order = true)
{
	vector<int> arr(3);
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	if (order)
	{
		return BozoSort(arr);
	}
	else
	{
		return BozoSort(arr, false);
	}
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
	int a, b, c;
	a = arr[0];
	b = arr[1];
	c = arr[2];
	cout << endl;
	arr = BozoSort(arr);
	ArrayOuter(arr, n);
	arr = BozoSort(arr, false);
	ArrayOuter(arr, n);
	arr = BozoSort(matrix);
	ArrayOuter(arr, n);
	arr = BozoSort(matrix, false);
	ArrayOuter(arr, n);
	arr = BozoSort(a, b, c);
	ArrayOuter(arr, 3);
	arr = BozoSort(a, b, c, false);
	ArrayOuter(arr, 3);
}