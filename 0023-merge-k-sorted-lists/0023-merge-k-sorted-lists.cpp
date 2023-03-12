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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto l:lists)
        {
            
            while(l!=NULL)
            {
               
                pq.push(l->val);
               
                l = l->next;
            }
        }
       
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while(pq.size())
        {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }
        
        return ans->next;
        
    }
};