#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        int count = 1;
        for (int m = 1; m < n; m++)
        {
            if (m + n == 1)
            {
                count++;
                cout << count << endl;
            }
        }
        cout << count << "\n";
    }
}