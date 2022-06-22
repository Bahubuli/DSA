#include<algorithm>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=k,i=nums.size();
        sort(nums.begin(),nums.end());
        
        return(nums[i-k]);
}
        
    
};