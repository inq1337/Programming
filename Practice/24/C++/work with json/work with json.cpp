#include <iostream>
#include <fstream>
#include <iomanip>
#include <json.hpp>

using nlohmann::json;

int main()
{
	std::ifstream input("in.json");
	json indata;
	input >> indata;
	int uc = 0, completed;
	for (int i = 0; i < indata.size(); i++)
	{
		if (indata[i]["userId"] >= uc)
			uc = indata[i]["userId"];
	}

	json outdata = json::array();
	for (int i = 1; i <= uc; i++)
	{
		completed = 0;
		for (int j = 0; j < indata.size(); j++)
			if (indata[j]["completed"] and indata[j]["userId"] == i)
				completed++;

		if (completed > 0)
		{
			json object;
			object["task_completed"] = completed;
			object["userId"] = i;
			outdata.push_back(object);
		}
	}
	std::ofstream output("out.json");
	output << std::setw(2) << outdata << std::endl;
}