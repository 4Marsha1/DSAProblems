#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr > dr || sc > dc)
    {
        return;
    }

    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return;
    }

    for (int jumps = 1; jumps <= dc - sc; jumps++)
    {
        printMazePaths(sr, sc + jumps, dr, dc, psf + "h" + (to_string)(jumps));
    }

    for (int jumps = 1; jumps <= dr - sr; jumps++)
    {
        printMazePaths(sr + jumps, sc, dr, dc, psf + "v" + (to_string)(jumps));
    }

    for (int jumps = 1; jumps <= dr - sr && jumps <= dc - sc; jumps++)
    {
        printMazePaths(sr + jumps, sc + jumps, dr, dc, psf + "d" + (to_string)(jumps));
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}
