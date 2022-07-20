/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--) {
            while(st.size()>0 && nums[st.top()]<=nums[i])
            st.pop();

            if(st.size()>0 && nums[st.top()]>nums[i])
            {
                ans[i]=st.top()-i;
            }
            else
            ans[i]=0;

            st.push(i);
        }
        return ans;
    }
};
// @lc code=end
