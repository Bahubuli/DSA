#include<bits/stdc++.h>
using namespace std;

void qsort(int *arr,int l,int r)
{
    if(l>=r) return;

    int pivot = arr[l];
    int i=r,j=r;
    while(i>l)
    {
        if(arr[i]>pivot)
        {
            swap(arr[i],arr[j]);
            j--;
        }
        i--;
    }
    swap(arr[l],arr[j]);

    qsort(arr,l,j-1);
    qsort(arr,j+1,r);
}

int main()
{
    int arr[] = {10,4,2,6,8,1,2,2,2};
    qsort(arr,0,8);

    for(int i=0;i<9;i++)
    cout<<arr[i]<<" ";
}
