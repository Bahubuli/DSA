#include <bits/stdc++.h>
#include <string>

using namespace std;

void printzigzag(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        printzigzag(n - 1);
        cout << n << " ";
        printzigzag(n - 1);
        cout << n << " ";
        }

    if (n == 0)
    {

        return;
    }
}

int main()
{
    int n;
    cin >> n;
    printzigzag(n);
}
