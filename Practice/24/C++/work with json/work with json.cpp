#include <iostream>
#include <fstream>
#include <json.hpp>
#include <iomanip>

using nlohmann::json;

int main()
{
	std::ifstream i("in.json");
	json in;
	i >> in;
	int *comp;
	int uc = 0;
	for (int i = 0; i < in.size(); i++)
	{
		if (in[i]["userId"] >= uc)
			uc = in[i]["userId"];
	}
	comp = new int[uc] { 0 };

	for (int i = 0; i < in.size(); i++)
	{
		for (int j = 1; j <= uc; j++)
		{
			if (in[i]["completed"] == true and in[i]["userId"] == j)
			{
				comp[j - 1]++;
			}
		}
	}

	json out = json::array();
	for (int j = 1; j <= uc; j++)
	{
		{
			json s;
			s["task_completed"] = comp[j - 1];
			s["userId"] = j;
			out.push_back(s);
		}
	}
	delete[] comp;
	std::ofstream o("out.json");
	o << std::setw(2) << out << std::endl;
}