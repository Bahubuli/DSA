#include<bits/stdc++.h>
using namespace std;

class stackusingarray{
    int *data;
    int nextIndex;
    int capacity;

public:
    stackusingarray()
    {
        capacity = 4;
        data = new int[capacity];
        nextIndex = 0;

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
              int *newdata = new int[2 * capacity];
                for(int i=0;i<capacity;i++)
                    newdata[i] = data[i];
                delete[] data;
                data = newdata;
        }
        capacity = capacity * 2;
        //cout << "capacity = " << capacity << " nxtibt " << nextIndex << endl;
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

        stackusingarray s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        s.push(70);
        s.push(80);
        cout << s.size() << endl;
      

        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.size() << endl;
}
