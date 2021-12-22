#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ----------- Declaration
    string str1;
    string str2 = "Hello World";
    string str3(10, 'b');
    // cout<<str2<<" "<<str3;

    // ------------ Input
    cin >> str1;        // without spaces
    getline(cin, str1); // with spaces

    // ----------- Operations
    string s1 = "abc";
    string s2 = "xyz";

    // 1. Append
    s1.append(s2);
    s1 = s1 + s2;

    // 2. Delete String Contents
    s1.clear();

    s1 = "abc";
    // 3. comparison  -----------> stringToCompare.compare(StringToCompareTo)
    cout << s2.compare(s1);

    // 4. Check if empty
    cout << s2.empty(); //---------> returns 1 if empty and otherwise 0

    // 5. Erase Characters  -----> str.erase(index, noOfChars)
    string s = "helloWorld";
    s.erase(3, 2);

    // 6. Find Char or Substring ----->  str.find("substring")
    s.find("wor"); //---------> returns first index of occurence

    // 7. insert char or substring ------> str.insert(index, "substring")
    s.insert(5, "wow"); //----------> inserts substring at index

    // 8. Length of string
    int len = s.size();
    int len = s.length();

    // 9. Get Substring ---------------> str.substr(index, noOfChars)
    string sub = s.substr(5, 5); //-------> returns noOfChars from index onwards

    // 10. String to int
    string s10 = "786";
    int x = stoi(s10);

    // 11. Int to string
    int y = 1024;
    string s9 = to_string(y);

    // 12. Sort a string ---------------> sorts lexicographically
    sort(s.begin(), s.end());

    // transform(stringBegin, stringEnd, IndexFromWhereTOStart, Function)
    // 13. Convert to all UpperCase
    string a = "asdbhasjbdhdbahjd";
    transform(a.begin(), a.end(), a.begin(), ::toupper);     //----------> transforms from first index
    transform(a.begin(), a.end(), a.begin() + 4, ::toupper); //----------> tranforms from 4th index

    // 14. Convert to all lowerCase
    transform(a.begin(), a.end(), a.begin(), ::tolower);
}