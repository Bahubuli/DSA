#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 65;
    char c = i;
    cout << "c = " << c << endl;

    int *p = &i;
    //char *pc=p; implicit typecasting error
    char *pc = (char *)p;

    cout << "*p = " << *p << endl;

    cout << "*pc = " << *pc << endl;

    cout << "p = " << p << endl;
    cout << "pc = " << pc << endl;

    cout << *(pc + 1) << endl; //null because it is not pointing towards anything
    cout << *(pc + 2) << endl;
    cout << *(pc + 3) << endl;
}
