class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        
        stack<int>st;
        long ans=0,mod=1e9+7;
        vector<long long >dp(n,0);
        for(int i=0;i<arr.size();i++)
        {
            while(st.size() && arr[st.top()]>arr[i]) st.pop();
            
            if(st.size())
            {
                dp[i]+= (i-st.top())*arr[i];
                
                dp[i]+= dp[st.top()];
                
            }
            
            else   dp[i]+= (i+1)*arr[i];
            
            dp[i] = dp[i]%mod;
            
            st.push(i);
        }
        
        for(auto s:dp) ans =(ans+s)%mod;
        
        return ans;
    }
};