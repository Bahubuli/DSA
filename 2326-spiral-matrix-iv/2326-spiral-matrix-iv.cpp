/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) 
    {
        vector<int> nums;
        ListNode *temp = head;
        
        
        vector<vector<int>>mat(n,vector<int>(m,-1));
        
        int u=0,l=0,d=n-1,r =m-1,p=0;
        
        while(l<=r && u<=d)
        {
            for(int col = l;col<=r && head;col++)
               {
                   mat[u][col] = head->val;
                   head = head->next;
               }
            
            if(++u>d) break;
            for(int row = u;row<=d && head;row++)
            {
              
               mat[row][r] = head->val;
                head = head->next;
               
            }
            
            if(--r<l) break;
            
            for(int col=r;col>=l && head;col--)
            {
               
               mat[d][col]=head->val;
                     head = head->next;
               
            }
            
            if(--d<u) break;
            
            for(int row=d;row>=u && head;row--)
            {
               
               
                   mat[row][l] = head->val;
                    head = head->next;
               
                
            }
            
            if(++l>r) break;
        }
        return mat;
        
        
    }
};