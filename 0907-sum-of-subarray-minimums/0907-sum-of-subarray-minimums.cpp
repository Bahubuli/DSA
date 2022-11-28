class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        
        stack<int>st;
        long ans=0,mod=1e9+7;
        vector<int>sum(n,0);
        for(int i=0;i<arr.size();i++)
        {
            while(st.size() && arr[st.top()]>arr[i]) st.pop();
            
            int j = st.size() ? st.top() : -1;
            
            sum[i] += (i-j)*arr[i]%mod;
            sum[i] += ((j<0)?0:sum[j]); 
            
            st.push(i);
        }
        
        for(auto s:sum) ans =(ans+s)%mod;
        
        return ans;
    }
};