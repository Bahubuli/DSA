class Solution {
public:
//     vector<int> nextGreaterElements(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<int>ans(n,-1);
//         stack<int> st;
        
//         for(int i=0;i<n*n;i++)
//         {
//             while(st.size() && nums[st.top()]<nums[i%n])
//             {
//                 ans[st.top()] = nums[i%n];
//                 st.pop();
//             }
//             st.push(i%n);
//         }
//         return ans;
        
//     }
    
     vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> stack, res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            while (stack.size() && A[stack.back()] < A[i % n]) {
                res[stack.back()] = A[i % n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return res;
    }
};