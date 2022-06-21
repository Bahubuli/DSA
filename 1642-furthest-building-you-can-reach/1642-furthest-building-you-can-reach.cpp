class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         priority_queue<int> pq;
        
        for(int i = 0; i+1 < heights.size(); i++){
            int distance = heights[i+1] - heights[i];
            
            //when we need to climb up
            //aways assume we are using ladder
            // (-ve) do the trick for creating min heap
            if(distance > 0){
                pq.push(-distance);
            }
            
            //if we can't use ladder 
            //then use bricks for the smallest difference
            // as min heap so bricks -= height becomes bricks -= (-height) ~ bricks += height
            if(pq.size() > ladders){
                bricks += pq.top();
                pq.pop();
            }
            
            //if we run out of bricks then we are done moving up
            if(bricks < 0) return i;
        }
        
        //we are here if we can reach the end of all building
        return heights.size()-1;
        
    }
};