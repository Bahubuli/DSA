#include<bits/stdc++.h>
using namespace std;


void edito()
{
    // don't use pow function
    // multiply by 2 in each iteration

}




int main()
 {

     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    long long int a,b,c;
    cin>>a>>b>>c;
     long long int ma=1;
     long long int mb=1;
     long long int x=b;

    for( long long int i=0;i<c;i++)
    {
        if(ma*a<b*mb)
        {
        x=a*ma;
        ma++;
        }
        else if(ma*a==mb*b)
        {
            x=ma*a;
            ma++;
            mb++;
        }
        else
        {
            x=b*mb;
            mb++;
        }


    }

int step,lcm;
for(int i=1;i<=a*b;i++)
{
    if(i%a==0 && i%b==0)
    { lcm=i;
    break;
    }
}

    if(x%a==0 && x%b==0)
    {
        step=lcm;

    }
    else if (x%a==0)
    {
         while(x>=0)
        {
            cout<<x<<" ";
            x=x-a;
        }

    }
    else
    {
         while(x>=0)
        {
            cout<<x<<" ";
            x=x-b;
        }

    }





while(x>=0)
        {
            cout<<x<<" ";
            x=x-step;
        }









//edito();


}
