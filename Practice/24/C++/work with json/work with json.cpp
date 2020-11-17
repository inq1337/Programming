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
	int *completed;
	int uc = 0;
	for (int i = 0; i < indata.size(); i++)
	{
		if (indata[i]["userId"] >= uc)
			uc = indata[i]["userId"];
	}
	completed = new int[uc] { 0 };

	for (int i = 0; i < indata.size(); i++)
	{
		if (indata[i]["completed"] == true)
			completed[indata[i]["userId"] - 1]++;
	}

	json outdata = json::array();
	for (int i = 1; i <= uc; i++)
	{
		json object;
		object["task_completed"] = completed[i - 1];
		object["userId"] = i;
		outdata.push_back(object);
	}
	delete[] completed;
	std::ofstream output("out.json");
	output << std::setw(2) << outdata << std::endl;
}