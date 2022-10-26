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

    void rehash()
    {
        mapnode<v>**temp = buckets;
        buckets = new mapnode<v>* [ 2 * numbuckets];
        for(int i=0;i<2*numbuckets;i++)
        {
            buckets[i]=NULL;
        }
        int oldbucketcount = numbuckets;
        numbuckets *=2;
        count=0;

        for(int i=0;i<oldbucketcount;i++)
        {
            mapnode<v>*head = temp[i];

            while(head!=NULL)
            {
                string key = head->key;
                v value = head->value;
                insert(key,value);
                head = head->next;
            }
        }

        for(int i=0;i<oldbucketcount;i++)
        {
            mapnode<v>*head = temp[i];
            delete head;
        }
        delete [] temp;

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
        int bucketidx = getbucketidx(key);
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
        double loadfactor = (double)count/numbuckets;
        if(loadfactor>0.7)
        {
           rehash();
        }
    }
    v getvalue(string key)
    {
        int bucketidx = getbucketidx(key);
        mapnode<v> *head = buckets[bucketidx];

        while(head!=NULL)
        {
            if(head->key == key)
                return head->value;
            head = head->next;
        }
        return 0;
    }
    v remove(string key)
    {
        int bucketidx = getbucketidx(key);
        mapnode<v> *head = buckets[bucketidx];
        mapnode<v> *prev = NULL;
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                    buckets[bucketidx] = head->next;

                else
                prev->next = head->next;

                v value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    double getloadfactor()
    {
        return (1.0 *count)/numbuckets;
    }

};

int main()
{

    ourmap<int> map;
    for(int i=0;i<20;i++)
    {
        char c = '0'+i;
        string key = "abc";
        key = key+c;
        int value = i+1;
        map.insert(key,value);
        cout<<map.getloadfactor()<<endl;
    }

    cout<<map.size()<<endl;

    cout<<map.getvalue("abc5")<<endl;

}
