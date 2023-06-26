/**
 * @param {number} n
 * @return {string}
 
 
n = 1: return 1 is the base case
n = 2: return count of last entry i.e. 1 1
n = 3: return count of last entry i.e. two 1's so 21
n = 4: we have one 2 and one 1 so 1211
n = 5: , we have one 1 and one 2 and two 1's so -> 111221
n = 6: we have three 1's, two 2's and one 1 so -> 312211
n = 7: we have one 3, one 1, two 2's and two 1's -> 13112221
 
 
 
 */



var countAndSay = function(m) 
{
    let  s = "1", ans="";
    if(m==1) return s;
 
    m--;
    while(m--)
        {
               let i=0,n=s.length;
          
             while(i<n)
                {
                    let c = 1;

                        if(i+1<n && s[i]==s[i+1])
                        {
                            while(i+1<n && s[i]==s[i+1])
                            {
                                i++;
                                c++;
                            }
                            ans+=`${c}`;
                            ans+=s[i];
                            i++;
                        }
                    
                        else 
                        {
                            ans+='1';
                            ans+=s[i];
                            i++;
                        }

                }
            s  = ans;
            ans = "";
        }
   
    return s;
};