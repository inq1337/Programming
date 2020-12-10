#include <iostream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int> arr, int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (arr[j] < arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите количество сигалов\n";
	cin >> n;
	vector<int> raw(n);
	cout << "Введите последовательность сигналов\n";
	for (int i = 0; i<n;i++)
	{
		cin >> raw[i];
	}

	vector<int> outer;
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		outer.push_back(raw[i]);
		size++;
		outer = BubbleSort(outer, size);
		if (size <= 5)
		{
			for (int j = 0; j < size; j++)
			{
				cout << outer[j] << " ";
			}
			cout << endl;
		}
		else
		{
			for (int j = size - 5; j < size; j++)
			{
				cout << outer[j] << " ";
			}
			cout << endl;
		}
	}
}