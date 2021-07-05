#include <bits/stdc++.h>
#include <string>

using namespace std;

void toh(int n, int id1, int id2, int id3)
{
    if (n == 0)
        return;

    toh(n - 1, id1, id3, id2);
    cout << n << "[" << id1 << " -> " << id2 << "]" << endl;
    toh(n - 1, id3, id2, id1);
}

int main()
{
    int id1, id2, id3, n;
    cin >> n >> id1 >> id2 >> id3;
    toh(n, id1, id2, id3);
}
