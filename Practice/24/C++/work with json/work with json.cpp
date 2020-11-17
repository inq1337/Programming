#include <iostream>
#include <fstream>
#include <json.hpp>

using nlohmann::json;
using std::ifstream;
using std::string;
int main()
{
	ifstream i("in.json");
	json in;
	i >> in;
	int comp[10] = { 0 };
	int j;
	for (int i = 0; i < in.size(); i++)
	{
		for (j = 1; j <= 10; j++)
		{
			if (in[i]["completed"] == true and in[i]["userId"] == j)
			{
				comp[j - 1]++;
			}
		}
	}
	for (j = 1; j<=10; j++)
		std::cout << j << " element is " << comp[j - 1] << std::endl; //очень предварительно, но пока дальше не продвинулся
}