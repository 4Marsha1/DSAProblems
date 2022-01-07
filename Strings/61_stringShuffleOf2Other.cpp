#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "1XY2";
    string s2 = "XY";
    string s3 = "12";

    if (s1.length() != s2.length() + s3.length())
    {
        cout << "False";
        return 0;
    }

    string temp = s2 + s3;
    sort(s1.begin(), s1.end());
    sort(temp.begin(), temp.end());
    if (temp.compare(s1) == 0)
        cout << "True";
    else
        cout << "False";
}