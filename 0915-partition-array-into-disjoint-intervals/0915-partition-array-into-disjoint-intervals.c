int max(int a,int b)
{
    return a>b?a:b;
}

int min(int a,int b)
{
    return a<b?a:b;
}

int partitionDisjoint(int* nums, int n)
{
    int left[n], right[n] ;
    
    left[0] = nums[0];
    right[n-1] = nums[n-1];
    for(int i=1;i<n;i++)
    {
        left[i] = max(left[i-1],nums[i]);
    }
    
     for(int i=n-2;i>=0;i--)
    {
        right[i] = min(right[i+1],nums[i]);
    }
    
    for(int i=1;i<n;i++)
    {
        printf("%d %d\n",left[i-1],right[i]);
        if(left[i-1]<=right[i])
            return i;
    }
    
    return n-1;

}