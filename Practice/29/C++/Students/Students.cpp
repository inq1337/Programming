#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::string;

struct Student
{
    std::map<std::string, int> data_exams;
    string data_name;
    int data_group;

    Student(std::string name, int group,
        int math, int phys, int hist, int prog)
    {
        using std::to_string;
        if (group < 1 or group > 9)
            throw std::invalid_argument("Invalid group. Got " + to_string(group));
        if (math < 0 or math > 9 or phys < 0 or phys > 9 or hist < 0 or hist > 9
            or prog < 0 or prog > 9)
            throw std::invalid_argument("Invalid notes. Got " +
                to_string(math) + ", " + to_string(phys) + ", " + to_string(hist)
                + ", " + to_string(prog));

        data_exams = { {"math", math}, {"phys", phys}, {"hist", hist}, {"prog", prog} };
        data_name = name;
        data_group = group;
    }

    friend
        std::ostream& operator << (std::ostream& out, const Student& student)
    {
        auto name_len = std::max(int(student.data_name.length()), 4);
        auto name_delim = string(name_len, '-');
        out << "+-" << name_delim << "-+-------+------+------+------+------+\n"
            << "| Name " << std::string(name_len - 4, ' ')
            << "| Group | Math | Phys | Hist | Prog |\n"
            << "+-" << name_delim << "-+-------+------+------+------+------+\n"
            << "| " << student.data_name << " | " << student.data_group
            << "     | " << student.data_exams.at("math")
            << "    | " << student.data_exams.at("phys")
            << "    | " << student.data_exams.at("hist")
            << "    | " << student.data_exams.at("prog")
            << "    |\n"
            << "+-" << name_delim << "-+-------+------+------+------+------+\n";
        return out;
    }

    bool operator < (const Student& other) const
    {
        return data_name < other.data_name;
    }
    bool operator > (const Student& other) const
    {
        return data_name > other.data_name;
    }
};

std::ostream& operator << (std::ostream& out, const std::vector<Student>& student_vec)
{
    auto name_len = student_vec.at(0).data_name.length();
    for (auto itr = student_vec.begin() + 1; itr != student_vec.end(); ++itr)
    {
        if (itr->data_name.length() > name_len)
        {
            name_len = itr->data_name.length();
        }
    }
    auto name_delim = std::string(name_len, '-');
    out << "+-" << name_delim << "-+-------+------+------+------+------+\n"
        << "| Name " << std::string(name_len - 4, ' ')
        << "| Group | Math | Phys | Hist | Prog |\n"
        << "+-" << name_delim << "-+-------+------+------+------+------+\n";

    for (auto& student : student_vec) 
    {
        out << "| " << student.data_name
            << std::string(name_len - student.data_name.length(), ' ')
            << " | " << student.data_group
            << "     | " << student.data_exams.at("math")
            << "    | " << student.data_exams.at("phys")
            << "    | " << student.data_exams.at("hist")
            << "    | " << student.data_exams.at("prog")
            << "    |\n"
            << "+-" << name_delim << "-+-------+------+------+------+------+\n";
    }
    return out;
};

template <class T>
std::vector<T> BozoSort(std::vector<T> arr, bool order = true)
{
    bool sorted = false;
    int n = arr.size();

    while (!sorted)
    {
        if (order)
        {
            std::swap(arr[rand() % n], arr[rand() % n]);

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
            std::swap(arr[rand() % n], arr[rand() % n]);

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

int main()
{
    std::srand(time(0));
    std::vector<Student> students = {
        Student("Yegor", 4, 3, 3, 2, 5),
        Student("Kyoko", 4, 3, 3, 3, 5),
        Student("Vasya", 4, 3, 5, 2, 5),
        Student("Clown", 4, 3, 3, 4, 5),
        Student("Luser232", 4, 3, 2, 3, 5),
        Student("Nikita", 2, 4, 3, 4, 5),
        Student("Andrew", 3, 4, 5, 3, 5),
        Student("Alex", 2, 2, 5, 3, 5),
        Student("George", 2, 3, 3, 4, 5),
        Student("Kotlyar", 2, 3, 3, 4, 5),
    };

    students = BozoSort(students);
}