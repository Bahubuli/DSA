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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *temp = head;
        
        ListNode *even = new ListNode(0);
        ListNode *eh = even;
        
        while(temp->next!=NULL)
        {
        even->next = temp->next;
        even = even->next;
        temp->next = temp->next->next;
            if(temp->next!=NULL)
            temp=temp->next;
        }
        even->next=NULL;
        temp->next = eh->next;
        return head;
        
    }
};