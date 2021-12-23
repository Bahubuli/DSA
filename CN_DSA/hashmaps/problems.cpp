
void reArrange(int arr[], int n)
{
    int i=0, j=1, k=0;
    while(i < n && j < n)
    {
        if(arr[i] % 2 == 0)
        {
            i = i+ 2;
        }
        else if(arr[j] % 2 == 1 )
        {
            j = j+ 2;
        }
        else if(arr[i] % 2 != 0)
        {
            swap(arr[i],arr[j]);
        }

}
