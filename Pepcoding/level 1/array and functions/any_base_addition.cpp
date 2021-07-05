#include <iostream>

using namespace std;

int getSum(int b, int n1, int n2)
{
    int carry = 0, m1 = 0, m2 = 0, sum = 0, i = 1;
    while (n1 > 0 || n2 > 0)
    {
        m1 = n1 % 10;
        m2 = n2 % 10;
        n1 = n1 / 10;
        n2 = n2 / 10;

        if (m1 + m2 + carry >= b)
        {

            sum = sum + (m1 + m2 - b + carry) * i;
            carry = 1;
            i = i * 10;
        }
        else
        {
            sum = sum + (m1 + m2 + carry) * i;
            carry = 0;
            i = i * 10;
        }
    }
    if (carry == 1)
        sum = sum + i * carry;
    return sum;
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getSum(b, n1, n2);
}