class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int n = heights.size();
        priority_queue<int> pq;
        
        for(int i=1;i<n;i++)
        {
            int d = heights[i]-heights[i-1];
            if(d<=0) continue;
            
            if(bricks-d>=0)
            {
                bricks -=d;
                pq.push(d);
            }
            else if(ladders>0)
            {
                if(pq.size() && pq.top()>d)
                {
                    bricks+= pq.top();
                    bricks-= d;
                    pq.pop();
                    pq.push(d);
                }
                ladders--;
            }
            else return i-1;
        }
        return n-1;
        
    }
};