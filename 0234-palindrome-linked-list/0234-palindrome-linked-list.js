/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */

function reverse(head)
{
    if(!head || !head.next) return head;
    
    let node = reverse(head.next);
    head.next.next = head;
    head.next = null;
    
    return node;
}

var isPalindrome = function(head) 
{
    if(!head || !head.next) return true;
    
    let p1 = head,p2 = head.next;
    
    while(p2 && p2.next)
    {
        p1 = p1.next;
        p2 = p2.next.next;
    }
    
    p2 = p1.next;
    p1.next = null;
    
    p2 = reverse(p2);
    p1 = head;
    while(p1 && p2)
    {
         if(p1.val!=p2.val) return false;
        p1 = p1.next;
        p2 = p2.next;
    }
    return true;
    
};