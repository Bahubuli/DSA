#include<bits/stdc++.h>
using namespace std;

#include "stackusingtemplates.h"

int main()
{
    stackusingT<char> s;
    s.push('c');
    s.push('a');
    s.push('b');
    s.push('d');
    s.push('e');
    s.push('f');

    cout << s.top() << endl;
}
