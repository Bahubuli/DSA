#include<bits/stdc++.h>
using namespace std;

class mystk
{
    public:
    stack<int> s;
    int minn;

    void getMin()
    {
        if(s.empty())
            cout << "stack is empty" << endl;
        else
        {
            cout << "Minimum element in the stack is : " << minn << endl;
        }
    }
    void peek()
    {
        if(s.empty())
            cout << "stack is empty";
        else
        {
            cout << s.top() << " is the min" << endl;
        }
    }

    void push(int x)
    {
        if(s.empty())
        {
            minn = x;
            s.push(x);
            cout << "number inserted  " << x << endl;
            return;
        }
        if(x>=minn)
        {
            s.push(x);
            cout << x << " inserted" << endl;
        }
        else
        {
            s.push(2 * x - minn);
            cout << 2 * x - minn << " inserted " << endl;
            minn = x;

        }

    }
    void pop()
    {
        if(s.empty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        int t = s.top();
        s.pop();
        if(t<minn)
        {
            cout << minn << endl;
            minn = 2 * minn - t;
        }
        else
        {
            cout << t << endl;
        }

    }


};
int main()
{
    mystk s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();

    return 0;
}
