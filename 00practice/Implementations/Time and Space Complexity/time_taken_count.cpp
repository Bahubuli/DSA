#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;

long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

    int main()
    {
        long starttime, endtime;
        starttime = getTimeinMicroSeconds();
        int sum = 0;
        for(int i=0;i<100;i++)
        {
           sum=sum+i;
           cout << sum << endl;
        }
        endtime = getTimeinMicroSeconds();

        cout <<"time taken is "<< endtime - starttime << endl;
    }
