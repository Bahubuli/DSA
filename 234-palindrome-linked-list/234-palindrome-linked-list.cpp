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
    
    ListNode *reverse(ListNode* head)
    {
        if(!head || !head->next) return head;
        
        ListNode *nxt,*prev=NULL,*curr=head;
        
        while(curr)
        {
            nxt = curr->next;
            curr->next= prev;
            prev = curr;
            curr=nxt;
        }
        return prev;
        
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode *s=head, *f=head->next;
        
        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
        }
        
        f = s->next;
        s->next = NULL;
        s = head;
        //cout<<f->val;
        f = reverse(f);
        
        //cout<<s->val<<" "<<f->val<<endl;
        while(s && f)
        {
            
            if(f->val!=s->val) return false;
            s = s->next;
            f = f->next;
        }
        return true;
        
        
        
    }
};