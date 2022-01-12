#include <iostream>
using namespace std;

void printPermutations(string str, string asf)
{
    if (str == "")
    {
        cout << asf << endl;
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        printPermutations(str.substr(0, i) + str.substr(i + 1), asf + str[i]);
    }
}

int main()
{
    string str;
    cin >> str;
    printPermutations(str, "");
}