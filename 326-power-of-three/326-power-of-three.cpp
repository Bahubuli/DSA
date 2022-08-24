class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        
        for(int i=0;i<32;i++)
        {
            long long int p3 = pow(3,i);
            if(p3==n) return true;
        }
        return false;
        
    }
};