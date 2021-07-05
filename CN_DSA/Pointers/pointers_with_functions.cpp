#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void increamentpointer(int *q)
{
    q = q + 1;
}

void increamentvalue(int *q)
{
    *q = *q + 1;
}
int sum(int *a, int size) //int a[] = int *a both same
{
    int s;
    cout << sizeof(a) << endl;
    for (int i = 0; i < size; i++)
        s = s + a[i];
    return s;
}
int main()
{
    int x = 5;
    int *p = &x;

    print(p);

    cout << p << endl;
    increamentpointer(p); //call by value
    cout << p << endl;

    cout << *p << endl;
    increamentvalue(p); //call by value
    cout << *p << endl;

    int a[10];
    a[2] = 99;
    cout << sizeof(a) << endl;
    cout << sum(a, 10);

    //you can also pass part of array
    cout << sum(a + 3, 7);
}