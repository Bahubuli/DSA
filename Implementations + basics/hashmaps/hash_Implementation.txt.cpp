#include<bits/stdc++.h>
using namespace std;
template<typename v>
class mapnode
{
    public:
        string key;
        v value;
        mapnode *next;

        mapnode(string key, v value)
        {
            this->key = key;
            this->value = value;
            next = NULL;
        }
        ~mapnode()
        {
            delete next;
        }
};

template<typename v>
class ourmap
{
    mapnode<v>** buckets;
    int count;
    int numbuckets;

    private:
    int getbucketidx(string key)
    {
        int hashcode =0;

        int currcof = 1;
        for(int i=key.length()-1;i>=0;i--)
        {
            hashcode += key[i] * currcof;
            //for out of range
            hashcode = hashcode % numbuckets;
            currcof *= 37;
            //for out of range
            currcof = currcof % numbuckets;
        }

        return hashcode % numbuckets;
    }

    public:
    ourmap()
    {
        count = 0;
        numbuckets = 5;
        buckets = new mapnode<v> *[numbuckets];
        for(int i=0;i<numbuckets;i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for(int i=0;i<numbuckets;i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
    int size()
    {
        return count;
    }
    void insert(string key,v value)
    {
        int bucketidx = getbucketidx(string key);
        mapnode<v> *head = buckets[bucketidx];
        while(head!=NULL)
        {
            if(head->key ==key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketidx];
        mapnode<v> *node = new mapnode<v>(key, value);
        node->next = head;
        buckets[bucketidx] = node;
        count++;
    }
    v getvalue(string key)
    {

    }
    v remove(string key)
    {

    }

};

int main()
{

}
