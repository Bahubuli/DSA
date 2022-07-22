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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *lhead = new ListNode(0), *ghead = new ListNode(0), *lp,*gp;
        lp = lhead, gp = ghead;
        
       
        ListNode *preh = new ListNode(5);
        preh->next = head;
        ListNode *temp = preh;
        
        while(temp->next)
        {
           
            if(temp->next->val<x)
            {
                lp->next = temp->next;
                lp = lp->next;
                temp->next = temp->next->next;
                lp->next = NULL;
            }
            else
            {
                gp->next = temp->next;
                gp = gp->next;
                temp->next = temp->next->next;
                gp->next = NULL;
            }
            
        }
        lp->next = ghead->next;
        return lhead->next;
        
        
    }
};