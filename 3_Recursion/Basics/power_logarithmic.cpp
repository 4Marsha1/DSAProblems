#include <iostream>
using namespace std;

int powerLogarithmic(int x, int n)
{
    if (n == 0)
        return 1;
    // diving the power by 2 ---> finding x^n/2
    int y = powerLogarithmic(x, n / 2);
    // if even ----> x^n = x^n/2 * x^n/2 ----> x^10 = x^5 * x^5
    if (n % 2 == 0)
        return y * y;
    // if odd -----> x^n = x^n/2 * x^n/2 * x ---> x^9 = x^4 * x^4 * x
    else
        return x * y * y;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << powerLogarithmic(x, n);
}