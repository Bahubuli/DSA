/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *p1 = headA, *p2 = headB;
        
        while(p1 || p2)
        {
            if(p1==NULL) p1 = headB;
            else if(p2==NULL) p2 = headA;
            
            if(p1==p2) return p1;
            
            p1 = p1->next;
            p2 = p2->next;
             if(p1==p2) return p1;
        }
        return NULL;
        
    }
};