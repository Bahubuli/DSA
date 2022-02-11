#include<bits/stdc++.h>
using namespace std;
//my implementation
void merges(int *arr,int l,int m,int h)
{
    int *arr2 = new int[h-l];

    int i=0;
    int j=l;
    int k=m;

    while(j<m && k<h)
    {
        if(arr[j]<arr[k])
        {
            arr2[i]=arr[j];
            i++;
            j++;
        }
        else
        {
            arr2[i]=arr[k];
            k++;
            i++;
        }
    }

    while(j<m)
    {
        arr2[i]=arr[j];
        i++;
        j++;
    }

     while(k<h)
    {
        arr2[i]=arr[k];
        i++;
        k++;
    }

    for(int i=l;i<h;i++)
    {

        arr[i]=arr2[i-l];
    }

}

void mergesort(int *arr,int l,int h)
{
 if(h-l==1)
 return;


    int m = (l+h)/2;


    mergesort(arr,l,m);
    mergesort(arr,m,h);

    merges(arr,l,m,h);



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
mergesort(arr,0,n);

for(int i=0;i<n;i++)
{
    cout<<arr[i]<<endl;
}

}
