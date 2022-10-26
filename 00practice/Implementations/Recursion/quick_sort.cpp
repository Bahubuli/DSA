#include<bits/stdc++.h>
using namespace std;
//my implementation

//partation function need little optimization
int partation(int *arr,int l,int r)
{
int p=l;

for(int i=l;i<=r;i++)
{
    //cout<<"partation fn";
    if(arr[i]<arr[p])
    {
        for(int j=i;j>p;j--)
        {
            //cout<<p<<" j = "<<j<<endl;
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;

        }
        p++;

    }
}

return p;



}

void quicksort(int *arr,int l,int r)
{
    if(l>r)
    {
        return;
    }

int c = partation(arr,l,r);

quicksort(arr,l,c-1);
quicksort(arr,c+1,r);

}


int main()
{
int n;
cin>>n;
int *arr = new int[n];

for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
quicksort(arr,0,n);

for(int i=0;i<n;i++)
{
    cout<<arr[i]<<endl;
}

}
