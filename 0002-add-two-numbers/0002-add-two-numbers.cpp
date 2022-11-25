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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // l1  = reverse(l1);
        // l2  = reverse(l2);
        
        ListNode *p1 = l1, *p2 = l2;
        
        int c = 0;
        
        ListNode *preh = new ListNode(0);
        ListNode *p3 = preh;
        while(p1 && p2)
        {
            p3->next = new ListNode((p1->val+p2->val+c)%10);
            c = (p1->val+p2->val+c)/10;
            
            p1 = p1->next;
            p2 = p2->next;
            p3 = p3->next;
        }
        
        while(p1)
        {
            p3->next = new ListNode((p1->val+c)%10);
            c = (p1->val+c)/10;  
            p1 = p1->next;
            p3 = p3->next;
        }
        
        while(p2)
        {
            p3->next = new ListNode((p2->val+c)%10);
            c = (p2->val+c)/10;  
            p2 = p2->next;
            p3 = p3->next;
        }
        if(c) p3->next = new ListNode(c);
        
        return  preh->next;
    }
};