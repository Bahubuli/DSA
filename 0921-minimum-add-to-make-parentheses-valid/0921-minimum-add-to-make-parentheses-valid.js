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
    let l=0,r=0;
    for(let i=0;i<s.length;i++)
        if(s[i]==')' && l) l--;
        else if(s[i]==')') r++;
        else l++;
    return l+r;
    
};