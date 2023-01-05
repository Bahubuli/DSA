class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        
         sort(points.begin(),points.end());
        int n=points.size();
        if(n==0) return 0;
        int ans=1,start=points[0][0],end=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0] > end){
               
                end=points[i][1];
                ans++;
            }
            else{
               
                end=min(end,points[i][1]);
            }
        }
        return ans;
        
    }
};