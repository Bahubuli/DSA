#include<bits/stdc++.h>
using namespace std;

#include "stackusingtemplates.h"

#include<stack>

int main()
{

    // stackusingT<char> s;
    // s.push('c');
    // s.push('a');
    // s.push('b');
    // s.push('d');
    // s.push('e');
    // s.push('f');
    // cout << s.top() << endl;
    stack<int> s;
    s.push(19);
    s.push(18);
    s.push(17);
    s.push(16);
    s.push(15);
    s.push(14);
    s.push(13);
    s.push(11);
    s.push(12);

    cout << s.top() << endl;

    s.pop();

    cout << s.top() << endl;

    cout << s.size() << endl;

    cout << s.empty() << endl;
    
}
