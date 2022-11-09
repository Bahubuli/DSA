class StockSpanner {
public:
    
    vector<int> nums;
    stack<int>st;
    
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
       nums.push_back(price);
       
        while(!st.empty() && nums[st.top()]<=price)
            st.pop();
       
        int ans;
        if(st.empty())
            ans = nums.size();
        else
            ans = nums.size()-1-st.top();
         st.push(nums.size()-1);
        return ans;
        
    }
};

