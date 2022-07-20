#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{

    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return;
    }

        for(int i=1;sc+i<=dc;i++)
        printMazePaths(sr, sc + i, dr, dc, psf + "h"+to_string(i));

        for(int i=1;sr+i<=dr;i++)
        printMazePaths(sr + i, sc, dr, dc, psf + "v"+to_string(i));

        for(int i=1;(sc+i<=dc && sr+i<=dr);i++)
        printMazePaths(sr + i, sc+i, dr, dc, psf + "d"+to_string(i));
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}