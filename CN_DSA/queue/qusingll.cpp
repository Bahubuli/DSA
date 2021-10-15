#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Node
{
    public:
        T data;
        Node<T> *next;
        Node(T data)
        {
            this->data = data;
            next = NULL;
        }
};

            template <typename T>

            class Queue
            {
                Node<T> *head;
                Node<T> *tail;
                int size;

            public:
                Queue()
                {
                    head = NULL;
                    tail = NULL;
                    size = 0;
                }

                int getsize()
                {
                    return size;
                }
                bool isempty()
                {
                    return size == 0;
                }

                void enqueue(T element)
                {
                    Node<T> *newNode = new Node<T>(element);
                    if (head == NULL)
                    {
                        head = newNode;
                        tail = newNode;
                    }
                    else
                    {
                        tail->next = newNode;
                        tail = tail->next;
                    }

                    size++;
                }

                T front()
                {
                    if (isempty())
                        return 0;
                    return head->data;
                }

                T dequeue()
                {
                    if (isempty())
                        return 0;

                    T ans = head->data;
                    Node<T> *temp = head;
                    head = head->next;
                    delete temp;
                    size--;
                    return ans;
                }

};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}
