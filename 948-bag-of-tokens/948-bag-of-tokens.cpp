class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int p) 
    {
        sort(nums.begin(),nums.end());
        
        int i=0,j = nums.size()-1;
        int ans = 0, score = 0;
        if(nums.size()==0) return 0;
        if(nums[0]>p) return 0;
        while(i<=j)
        {
            
            if(nums[i]<=p)
            {
                p -= nums[i];
                score++;
                i++;
            }
            else
            {
                p+=nums[j];
                score--;
                j--;
            }
            
            ans = max(ans,score);
        }
        return ans;
        
    }
};