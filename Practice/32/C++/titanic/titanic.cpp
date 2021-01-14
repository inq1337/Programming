#pragma warning(disable:4996) //to disable secure warnings, wich cased by csv.hpp
#include <iostream>
#include <tuple>
#include <csv.hpp> //https://github.com/vincentlaucsb/csv-parser

using std::string;
using std::vector;

struct Passenger {
	bool survival;
	short pclass;
	string name;
	string sex;
	float age;
	short sibsp;
	short parch;
	string ticket;
	float fare;
	string cabin;
	char embarked;
};

std::istream& operator>> (std::istream& in, vector<Passenger>& passengers) 
{
	csv::CSVReader reader("train.csv");

	for (auto& row : reader) 
	{
		Passenger passenger {
			row["Survived"].get<bool>(),
			row["Pclass"].get<short>(),
			row["Name"].get(),
			row["Sex"].get(),
			row["Age"].get<float>(),
			row["SibSp"].get<short>(),
			row["Parch"].get<short>(),
			row["Ticket"].get(),
			row["Fare"].get<float>(),
			row["Cabin"].get(),
			row["Embarked"].get<char>()
		};
		passengers.push_back(passenger);
	}

	return in;
}

std::ostream& operator << (std::ostream& out, vector<Passenger>& passengers)
{
	auto writer = csv::make_csv_writer(out);

	writer << vector<string>({"Survived", "Pclass", "Name", "Sex", "Age", "SibSp", "Parch", "Ticket", "Fare", "Cabin", "Embarked"});

	for (auto& pass : passengers) 
	{
		writer << std::make_tuple(
			pass.survival,
			pass.pclass,
			pass.name,
			pass.sex,
			pass.age,
			pass.sibsp,
			pass.parch,
			pass.ticket,
			pass.fare,
			pass.cabin,
			pass.embarked
		);
	}

	return out;
}

int main()
{

}