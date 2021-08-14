#include<bits/stdc++.h>
using namespace std;
template <typename T>

class stackusingT
{
    T *data;
    int nextIndex;
    int capacity;

public:
    stackusingT()
    {
        capacity = 4;
        data = new T[capacity];
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
    void push(T el)
    {
        if (nextIndex == capacity)
        {
            T *newdata = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
                newdata[i] = data[i];
            delete[] data;
            data = newdata;
        }
        capacity = capacity * 2;
        //cout << "capacity = " << capacity << " nxtibt " << nextIndex << endl;
        data[nextIndex] = el;
        nextIndex++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        return data[nextIndex - 1];
    }
};

int main()
{
    stackusingT<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    cout << s.top() << endl;
    cout << s.size() << endl;
}
