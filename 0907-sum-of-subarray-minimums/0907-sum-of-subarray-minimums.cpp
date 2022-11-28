class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size(),mod=1e9+7;
        vector<int>left(n,0),right(n,0);
        
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(st.size() && arr[st.top()]>arr[i])
                st.pop();
            
            left[i] = st.size()?i-st.top():i+1;
            st.push(i);
        }
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(s.size() && arr[s.top()]>=arr[i]) s.pop();
            
            right[i] = s.size()?s.top()-i:n-i;
            s.push(i);
        }
        long long  ans = 0;
        
        for(int i=0;i<n;i++)
            ans = (ans+(long long)arr[i]*left[i]*right[i])%mod;
        
        return ans;
        
    }
};