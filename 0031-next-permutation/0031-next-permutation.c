void reverse(int* nums,int n)
{
    int i = 0,j=n-1;
    while(i<=j)
    {
        swap(&nums[i],&nums[j]);
        i++;
        j--;
    }
}

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void nextPermutation(int* nums, int n)
{

    int i;
    for(i=n-2;i>=0;i--)
        if(nums[i]<nums[i+1])
            break;
    
    if(i<0)
    {
        reverse(nums,n);
    }
    else
    {
        for(int j=n-1;j>i;j--)
        {
            if(nums[j]>nums[i])
            {
                swap(nums+i,nums+j);
                break;
            }
        }
        int j = n-1;
        i++;
        while(i<j)
        {
            swap(nums+i,nums+j);
            i++;
            j--;
        }
    }

}