#include <bits/stdc++.h>
using namespace std;

void increment(int &n)
{
    n++;
}

// Never ever return functions local variable's reference
// or address to main() functions because the scope will be lost
// make sure you return main() function variable address or reference
// during functions like int* f1() int& f2()

int main()
{
    int i = 65;
    int j = i;
    i = 45;
    cout << i << endl;
    cout << j << endl;

    int &k = j; //reference variable need to initialized
    k = k + 10;
    cout << j << endl;
    cout << k << endl;
    increment(k);
    cout << k << endl;
    //reference is helping us in sharing the main function variables with other functions
}