
class Solution {
public:
    
    ListNode* reverse(ListNode *head)
    {
        ListNode *prev = NULL,*curr=head,*nxt;
        
        while(curr)
        {
            nxt=curr->next;
            curr->next = prev;
            prev = curr;
            curr=nxt;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *temp = dummy;
        
        while(temp)
        {
            ListNode *hk=NULL, *tk=NULL,*prevHK=NULL,*nextTK=NULL;
            
            prevHK = temp;
            hk = temp->next;
            
            for(int i=0;(i<k) && (temp);i++) temp=temp->next;
            
            
            if(!temp ) break;
          
            tk = temp;
            nextTK = tk->next;
            tk->next = NULL;
            
            reverse(hk);
            
            prevHK->next = tk;
            hk->next  = nextTK;
            temp = hk;
            
        }
        
        return dummy->next;
    }
};