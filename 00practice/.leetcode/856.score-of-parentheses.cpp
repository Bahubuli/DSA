/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string s)
    {
    stack<char>st;
    int i=0;
    int ans =0;
    int l=1,m=1;
    while(i<s.length()) {
        if(s[i]==')') {
            if(!st.empty() && st.top()=='(') {
                st.pop();
                ans+=m*l;
                l=m;
                m=m*2;
            }
        }
        else
        {
            l=1;
            m=1;
            st.push(s[i]);
        }
        i++;
    }
    return ans;

    }
};
// @lc code=end
