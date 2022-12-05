/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head) return head;
        Node *temp = head, *copy,*ans=NULL;
        
        while(temp)
        {
            copy = new Node(temp->val);
            if(ans==NULL) ans = copy;
            copy->next = temp->next;
            temp->next = copy;
            
            temp = copy->next;
        }
        
        temp = head;
        
        while(temp && temp->next)
        {
            if(temp->random)temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        
        temp = head;
        Node *temp2 =temp->next;
        
        while(temp)
        {
            temp2 = temp->next;
            if(temp->next) temp->next = temp->next->next;
            if(temp2->next) temp2->next = temp2->next->next;
            
            temp =temp->next;
            temp2 = temp2->next;
        }
        return ans;
    }
};