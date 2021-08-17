#include<bits/stdc++.h>
using namespace std;

#include "qarray.h"

int main()
{
    qarray<int> q(5);
    q.enq(5);
    q.enq(6);
    q.enq(7);
    q.enq(8);
    q.enq(9);
    q.enq(10);

    cout << q.front() << endl;
    cout << q.deq() << endl;
    cout << q.deq() << endl;
    cout << q.deq() << endl;

    cout << q.getsize() << endl;
    cout << q.isEmpty() << endl;
}
