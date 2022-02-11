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

int getProduct(int b, int n1, int n2)
{
    int m1, m2, result = 0, c, mu, mul = 0, i = 1, j = 1, r, n2d = n2;
    while (n1)
    {
        m1 = n1 % 10;
        c = 0, mul = 0, i = 1;
        n2 = n2d;
        while (n2 || c > 0)
        {
            m2 = n2 % 10;

            mu = m2 * m1 + c;
            c = mu / b;
            r = mu % b;
            mul = mul + r * i;
            cout << "mul = " << mul << " ";

            i = i * 10;

            n2 = n2 / 10;
        }
        cout << "\n";
        result = getSum(b, result, mul * j);
        j = j * 10;

        n1 = n1 / 10;
    }
    return result;
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getProduct(b, n1, n2) << endl;
}