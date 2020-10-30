#include <iostream>
using namespace std;

string pattern = "a???55661";

bool IsTicketValid(string code)
{
	if (code.length() == pattern.length())
	{
		if ((code[0] == 97) and (97 <= code[1]) and (code[1] <= 122))
		{
			for (int i = 2; i < pattern.length(); i++)
			{
				if (pattern[i] == '?')
				{
					if ((48 <= code[i]) and (code[i] <= 57))
						continue;
					else
						return false;
				}
				else
				{
					if (code[i] == pattern[i])
						continue;
					else
						return false;
				}
			}
		}
		else
			return false;
		return true;
	}
	else
		return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, k = 0;
	string code, answer;
	while (true)
	{
		cout << "Введите количество билетов\n";
		cin >> n;
		if (n > 0)
		{
			cout << "Введите билеты\n";
			for (int i = 0; i < n; i++)
			{
				cin >> code;
				if (IsTicketValid(code) == true)
				{
					answer = answer + code + " ";
					k++;
				}
			}
			if (k > 0)
				cout << answer;
			else
				cout << -1;
			break;
		}
		else
		{
			cout << "Количество билетов должно быть больше нуля\n\n";
			continue;
		}
	}
}