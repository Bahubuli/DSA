// Problem Name: Move All X at End
// Problem Difficulty: None
// Problem Constraints: Length of string <= 1000
// Problem Description:
// Take as input str, a string. Write a recursive function which moves all ‘x’ from the string to its end.
 //E.g. for “abexexdexed” return “abeedeedxxx”. Print the value returned

// Input Format: Single line input containing a string
// Sample Input: axbxc
// Output Format: Single line displaying the string with all x's moved at the end
// Sample Output: abcxx
#include<bits/stdc++.h>
using namespace std;

string mxtoend(string s)
{
    if(s.length()==0)
    {
        return s;
    }

    string s2 = mxtoend(s.substr(1));

    if(s[0]=='x')
    {
        return s2+'x';
    }
    return s[0]+
    s2;
}

int main()
{
    string s;
    cin>>s;
    cout<<mxtoend(s)<<endl;
}
