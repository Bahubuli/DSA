void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(int *nums,int i,int j)
{
    while(i<j)
    {
        swap(&nums[i],&nums[j]);
        i++;
        j--;
    }
}
void nextPermutation(int* nums, int n)
{
    int i;
    for(i=n-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
           
            break;
        }
    }
    
    if(i<0)
    {
        reverse(nums,0,n-1);
        return;
    }
    
    for(int j=n-1;j>i;j--)
    {
        if(nums[j]>nums[i])
        {
            swap(&nums[i],&nums[j]);
            reverse(nums,i+1,n-1);
            return;
        }
    }

}