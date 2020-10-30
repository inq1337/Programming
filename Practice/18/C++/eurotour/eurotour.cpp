#include <iostream>
using namespace std;

string dictionary = "hallo, klempner, das, ist, fantastisch, fluggegecheimen";

string remover(string d)
{
    for (int i = 0; i < d.length(); i++)
        if (d[i] == ',' or d[i] == ' ')
        {
            d.erase(i, 1);
            i--;
        }
    return d;
}

double counter(string dmerged, char letter)
{
    int q = 0;
    for (int i = 0; i < dmerged.length(); i++)
    {
        if (dmerged[i] == letter)
            q++;
    }
    return q;
}
int main()
{
    setlocale(LC_ALL, "Russian");

    double prob = 1;
    string dmerged, stop;
    dmerged = remover(dictionary);
    cout << "Введите стоп-слово\n";
    cin >> stop;
    for (int i = 0; i < stop.length(); i++)
        prob = prob * (counter(dmerged, stop[i]) / dmerged.length());
    cout << "Вероятность для стоп-слова: " << prob;
}