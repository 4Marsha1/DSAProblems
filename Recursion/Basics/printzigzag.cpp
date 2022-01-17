// Input->1
// Output->1 1 1

// Input->2
// Output->2 1 1 1 2 1 1 1 2

// Input->3
// Output->3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3

#include <iostream>
using namespace std;

void pzz(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    pzz(n - 1);
    cout << n << " ";
    pzz(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    pzz(n);
}
