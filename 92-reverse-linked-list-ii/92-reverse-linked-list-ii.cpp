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
    
    ListNode *reverse(ListNode *head)
    {
        if(!head || !head->next) return head;
        
        ListNode *node = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *preh = new ListNode(0);
        preh->next = head;
        ListNode *lnode = preh,*rnode = preh,*temp;
        
        for(int i=1;i<left;i++) lnode = lnode->next;
        for(int i=1;i<=right;i++) rnode = rnode->next;
        
        ListNode *rest = rnode->next;
        rnode->next = NULL;
        
        lnode->next = reverse(lnode->next);
        while(lnode->next) lnode = lnode->next;
        lnode->next = rest;
        return preh->next;
    }
};