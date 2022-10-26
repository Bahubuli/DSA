#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    char s[] = "Satya";
    char *ptrs = "Satya"; //prone to errors due to temp memory

    cout << "a = " << a << endl; //a = 0x61fefc
    cout << "s = " << s << endl; //s = Satya

    char *pc = &s[0];

    cout << "pc = " << pc << endl; //pc = Satya

    char c = 'j';
    char *cp = &c;

    cout << "cp = " << cp << endl; //cp = jSatya or j+ garbage till '\0'
}