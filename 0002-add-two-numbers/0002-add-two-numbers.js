/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) 
{
    
    
    let preh = new ListNode(0);
    let p3 = preh,c=0;
    
    while(l1 || l2)
    {
        let a = l1 && l1.val;
        let b = l2 && l2.val;
        let sum = a+b+c;
        
        c = Math.floor(sum/10) 
        p3.next = new ListNode(sum%10);
        
        if(l1) l1=l1.next;
        if(l2) l2=l2.next;
        p3 = p3.next;
       
        
    }
    if(c) p3.next = new ListNode(c);
    
    return preh.next;
    
};