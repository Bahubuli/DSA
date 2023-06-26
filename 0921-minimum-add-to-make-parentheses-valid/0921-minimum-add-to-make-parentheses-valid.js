/**
 * @param {string} s
 * @return {number}
 */

function  helper(s,i,op,cl)
{
    if(i==s.length) return op+cl;
    if(s[i]==')' && op>0) return helper(s,i+1,op-1,cl);
    else if(s[i]==')') return helper(s,i+1,op,cl+1);
    else return helper(s,i+1,op+1,cl);
}

var minAddToMakeValid = function(s) 
{
    return helper(s,0,0,0);
    
};