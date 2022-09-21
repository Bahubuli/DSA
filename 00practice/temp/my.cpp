#include <bits/stdc++.h>
using namespace std;

void PrefixToInfix(stack<string> &stk, string prefix)
{
    int n = prefix.size() - 1;

    // we will traverse the given prefix expression from right to left
    for (int i = n; i >= 0; i--)
    {

        string currentVal = prefix.substr(i,1);


        //cout<<currentVal<<endl;

        // if an operator is encountered
        // then pop out the last inserted two elements
        // and concatenate them along with the operator & brackets
        // and push the resultant back into the stack
        if (currentVal == "+" || currentVal == "-" || currentVal == "/" || currentVal == "*" || currentVal == "^" || currentVal == "%")
        {
            string first = stk.top();
            stk.pop();
            string second = stk.top();
            stk.pop();

            string newVal = "(" + first + currentVal + second + ")";
            stk.push(newVal);
        }

        else
            // if we'll encounter any operand then we'll simply push it into the stack
            stk.push(currentVal);
    }
}

int main()
{
    string prefix;
    cout << "Enter a valid prefix expression : ";
    cin >> prefix;

    stack<string> stk;

    PrefixToInfix(stk, prefix);

    cout << "The infix expression of the given prefix expression is : " << stk.top();

    return 0;
}
