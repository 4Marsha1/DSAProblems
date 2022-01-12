#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf)
{
    if (ques == "")
    {
        cout << asf << endl;
        return;
    }
    string code = codes[ques[0] - '0'];
    for (int i = 0; i < code.length(); i++)
    {
        printKPC(ques.substr(1), asf + code[i]);
    }
}

int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
}