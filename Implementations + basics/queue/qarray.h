
template <typename T>
class qarray
{
    T *data;
    int nextidx;
    int firstidx;
    int size;
    int capacity;

public:
    qarray(int s)
    {
        data = new T(s);
        nextidx = 0;
        firstidx = -1;
        size = 0;
        capacity = s;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    //insert element
    void enq(T el)
    {
        if (size == capacity)
        {
            T *newdata = new T[2 * capacity];
            int j = 0;
            for (int i = firstidx; i < capacity; i++)
            {
                newdata[j] = data[i];
                j++;
            }

            delete[] data;
            T * data = newdata;
            firstidx = 0;
            nextidx = capacity;
            capacity = capacity * 2;
        }

        data[nextidx] = el;
        nextidx = (nextidx + 1) % capacity;
        if (firstidx == -1)
            firstidx = 0;
        size++;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        else
        {
            return data[firstidx];
        }
    }

    T deq()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        T ans = data[firstidx];
        firstidx = (firstidx + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstidx = -1;
            nextidx = 0;
        }
        return ans;
    }
};
