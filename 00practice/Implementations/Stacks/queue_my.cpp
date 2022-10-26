#include<bits/stdc++.h>
using namespace std;

class mystack
{
    int capacity;
    int tp;
    int *sarr;
    public:

    mystack(int n)
    {
        sarr = new int[n];
        capacity=n;
        tp=-1;
    }

    void push(int x)
    {
        tp++;
        if(tp==capacity)
        {
            int *newst = new int[capacity*2];
            for(int i=0;i<tp;i++)
            {
                newst[i] = sarr[i];
            }
            sarr = newst;
            capacity = capacity*2;
        }
        sarr[tp] = x;
    }
    int top()
    {
        if(tp<0)
        {
            cout<<"stack is empty"<<endl;
             return INT_MIN;
        }
        return sarr[tp];

    }
    void pop()
    {
        if(tp>=0) tp--;
    }
    bool isempty()
    {
        return tp<0;
    }
};

int main()
{
    mystack stk(5);
    stk.push(53);
    cout<<stk.top()<<endl;
    stk.pop();
    stk.pop();


}
