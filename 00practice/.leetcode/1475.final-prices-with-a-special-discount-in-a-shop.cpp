/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && st.top()>prices[i])
            st.pop();
            if(st.size()>0 && st.top()<=prices[i])
            ans[i]=prices[i]-st.top();
            else
            ans[i]=prices[i];

            st.push(prices[i]);
        }
    return ans;
    }
};
// @lc code=end
