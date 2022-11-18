class Solution {
public:
    bool isUgly(int n) 
    {
        while(n%2==0 && n) n = n/2;
        while(n%5==0 && n) n = n/5;
        while(n%3==0 && n) n = n/3;
        
        return n==1;
        
    }
};