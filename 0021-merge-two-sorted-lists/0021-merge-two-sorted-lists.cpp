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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *p1 = list1, *p2 = list2;
        
        ListNode *preh = new ListNode(-1);
        ListNode *temp = preh;
        
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val<p2->val)
            {
                temp->next = p1;
                p1 = p1->next;
            }
            else 
            {
                temp->next =p2;
                p2 = p2->next;
            }
            temp=temp->next;
        }
        
        if(p2!=NULL) temp->next = p2;
        if(p1!=NULL) temp->next = p1;
        
        return preh->next;
    }
};