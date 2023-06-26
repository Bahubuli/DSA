//{ Driver Code Starts
//Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let obj = new Solution();
        let ans=obj.lookandsay(n);
        console.log(ans);
    }
}

// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} n
 * @returns {string}
*/
class Solution {
    
    lookandsay(m)
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
       
    }
}