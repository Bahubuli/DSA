void rotate(int* nums, int n, int k)
{
    
    k = k%n;
    k = (n-k)%n;
    
    int i=0,j=k-1;
    while(i<j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
    }
    i = k,j=n-1;
    
    while(i<j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
    }
    
    i = 0,j=n-1;
      while(i<j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
    }
}