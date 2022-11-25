/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) 
{
    
    let p1 = headA, p2 = headB,tailA=null,tailB=null;
    
    while(p1 || p2)
    {
        
        if(p1==null) p1 = headB;
        if(p2==null) p2 = headA;
        
        if(p1==p2) return p1;
        
        p1 = p1.next;
        p2 = p2.next;
            
            
    }
    return null;
};