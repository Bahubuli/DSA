#include <iostream>

using namespace std;

int getSum(int b, int n1, int n2)
{
    int borrow = 0, m1 = 0, m2 = 0, sub = 0, i = 1;
    while (n1 > 0 || n2 > 0)
    {
        m1 = n1 % 10;
        m2 = n2 % 10;
        n1 = n1 / 10;
        n2 = n2 / 10;

        if (m2 - borrow < m1)
        {

            sub = sub + (m2 + b - borrow - m1) * i;
            borrow = 1;
            i = i * 10;
        }
        else
        {
            sub = sub + (m2 - m1 - borrow) * i;
            i = i * 10;
            borrow = 0;
        }
    }
    return sub;
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getSum(b, n1, n2);
}