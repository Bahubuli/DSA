#include <bits/stdc++.h>
using namespace std;

	int NthRoot(int n, int m)
	{


	    if(m == 1)
	        return 1;

	    int l=2,h=m;

	    int mid;
	    while(l<=h)
	    {
	         mid = l+(h-l)/2;
	        long long int p = pow(mid,n);
            cout << "power " <<p<<  endl;
            if(p==m)
	        {
	            return mid;
	        }
	        else if(p>m || p<0)
	        {
	          h=mid-1;
	        }
	        else
	        {
	          l=mid+1;
	        }


	    }

	    return -1;


	}
int main()
{
    cout << NthRoot(6, 4096);
}
