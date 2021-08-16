#include<bits/stdc++.h>
using namespace std;
template <typename T>

class Node{
    public:
        T data;
        Node<T> *next;
        Node(T data){
            this->data = data;
            next = NULL;
        }
};
template <typename T>
class stackusingll
{
    Node<T> *head;
    int gtsize=0;

public:
    Stack()
    {
        head = NULL;
        gtsize = 0;
    }
    int getsize()
    {
        return gtsize;
    }
    bool isempty()
    {
        return gtsize == 0;
    }
    void push(int el)
    {
        Node<T> *newN = new Node<T>(el);
        newN->next = head;
        head = newN;
        gtsize++;
        cout << gtsize << " ";
    }

    T pop()
    {
        T value = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        gtsize--;
        return value;
    }
    T top()
    {
        if (!isempty())
            return head->data;
        return -1;
    }
};

int main()
{
    stackusingll<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    cout << s.getsize() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getsize() << endl;
}
