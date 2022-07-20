#include<iostream>

using namespace std;

int *ind(int *A ,int i ,int x,int fsf,int &val, int n)
{
    if(i==n){
    int *p =new int[1];
    val=fsf;
    return p;
    }

    if(A[i]==x){
    int *p=ind(A,i+1,x,(fsf+1),val,n);
    *(p+fsf)=i;

    return p;
    }
    else{
    return ind(A,i+1,x,fsf,val,n);
    }



}
main()
{
    int n;int A[10000];
    cin>>n;
    for(int i =0 ; i<n;i++)
    cin>>A[i];
    int x;cin>>x;
    int fsf=0, val=0;

    int *p;
    p=ind(A,0,x,fsf,val,n);
   // cout<<val<<endl;
    for(int i=0; i<val;i++)
    cout<<*(p+i)<<endl;

}
