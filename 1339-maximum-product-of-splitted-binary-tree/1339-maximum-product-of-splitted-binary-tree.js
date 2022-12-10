/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var sumt = function(node)
{
    if(!node) return 0;
    return node.val+sumt(node.left)+sumt(node.right);
}

var dfs= function(node,s,ans)
{
    if(!node) return 0;
    
    const l = dfs(node.left,s,ans);
    const r = dfs(node.right,s,ans);
    
    ans.res = Math.max(ans.res,l*(s-l));
    ans.res = Math.max(ans.res,r*(s-r));
    
    return(node.val+l+r);
}

var maxProduct = function(root) 
{
    let mod = Math.pow(10,9)+7;
    let s = sumt(root);
    console.log(s)
    let ans  = {"res":0};
    dfs(root,s,ans);
    return ans.res%mod;

};