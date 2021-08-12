#include<bits/stdc++.h>
using namespace std;

class stackusingarray{
    int *data;
    int nextIndex;
    int capacity;

public:
    stackusingarray(int totalsize)
    {
        data = new int[totalsize];
        nextIndex = 0;
        capacity = totalsize;
    }

    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    void push(int el)
    {
        if(nextIndex == capacity)
        {
            cout << "stack full" << endl;
            return;
        }
        cout << "capacity = " << capacity << " nxtibt " << nextIndex << endl;
        data[nextIndex] = el;
        nextIndex++;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];

    }

    int top()
    {
        return data[nextIndex - 1];
    }

};

int main()
{
        // freopen("i.txt", "r", stdin);
        // freopen("o.txt", "w", stdout);

        stackusingarray s(5);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        s.push(70);
        s.push(80);
        cout << s.size() << endl;
        cout << s.top() << endl;

        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.size() << endl;
}
