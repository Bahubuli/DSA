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
    bool isPalindrome(ListNode* head)
    {
        stack<int>st;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while(p2!=NULL && p2->next!=NULL)
        {
            st.push(p1->val);
            
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        if(p2!=NULL) p1 = p1->next;
        
        while(st.size())
        {
            if(st.top()==p1->val)
            {
                st.pop();
                p1 = p1->next;
            }
            else 
                return false;
        }
        
        return true;
    }
};