#include <bits/stdc++.h>
#include <string>

using namespace std;

void printpermutations(string s, int t)
{

    int n = s.length(), i = 0;

    while (i < t)
    {
        string s2 = s;
        int x = n, p = 0, j = i;

        while (x)
        {
            int r = j % x;

            cout << s2[r];
            s2.erase(r, 1);

            j = j / x;

            x--;
        }
        cout << "\n";

        i++;
    }
}

int main()
{
    string s;

    getline(cin, s);
    int n = s.size(), totalp = 1;

    for (int i = 2; i <= n; i++)
    {
        totalp = totalp * i;
    }



    printpermutations(s, totalp);
}
