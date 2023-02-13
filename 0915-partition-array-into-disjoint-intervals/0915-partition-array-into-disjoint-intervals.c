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
    int ans = 0;
    int leftmx = nums[0];
    int currmx = nums[0];
    for(int i=0;i<n;i++)
    {
        currmx = max(currmx,nums[i]);
        
        if(nums[i]<leftmx)
        {
            leftmx = max(currmx,leftmx);
            ans = i;
        }
        
    }
    return ans+1;
}