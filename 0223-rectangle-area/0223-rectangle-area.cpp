class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int ans = (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);
        
        if(ax1>=bx2 || ay1>=by2 || bx1>=ax2 || by1>=ay2) return ans;
        else
        {
            int allx[] = {ax1,ax2,bx1,bx2};
            int ally[] = {ay1,ay2,by1,by2};
            
            sort(allx,allx+4);
            sort(ally,ally+4);
            
            ans-= (allx[2]-allx[1])*(ally[2]-ally[1]);
        }
        return ans;
        
    }
};