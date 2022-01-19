#include <iostream>
#include <string>
using namespace std;

void printEncoding(string str, string asf)
{
    if (str.length() == 0)
    {
        cout << asf << endl;
        return;
    }
    else if (str.length() == 1)
    {
        if (str[0] == '0')
            return;
        else
        {
            char code = (char)('a' + str[0] - 1);
            cout << asf + code << endl;
            return;
        }
    }
    else
    {
        if (str[0] == '0')
            return;
        else
        {
            char code = (char)('a' + str[0] - 1);
            printEncoding(str.substr(1), asf + code);
        }

        int ch = stoi(str.substr(0, 2));
        if (ch <= 26)
        {
            char code = (char)('a' + ch - 1);
            printEncoding(str.substr(2), asf + code);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    printEncoding(str, "");
}