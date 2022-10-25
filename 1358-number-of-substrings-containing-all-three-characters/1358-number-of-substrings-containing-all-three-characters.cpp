class Solution {
public:
    int numberOfSubstrings(string s) 
    {
//          int count = 0;
//         int release = 0;
//         int end = s.size()-1;
//         unordered_map<char,int>memo;
        
        
//         for(int acquire = 0; acquire < s.size(); acquire++)
//         {   
//             //acquire the current element in the map
//             memo[s[acquire]]++;
            
//             if(memo['a']  && memo['b'] && memo['c']) 
//             {
//                 //add 1 + end - acquire to count
//                 // 1-> for the current substring
//                 //since the current sub-string has all the three characters
//                 //so all its following sub-strings will also have 3 characters
//                 //therefore also add (end - acquire)
//                 count += 1 + (end - acquire);
                
//                 //now since we have got count of all the sub-strings having all the 3                      // characters starting from release index
//                 //so release that element and move the window forward
//                 memo[s[release]]--;
//                 release++;
//             }
            
//         }
//         return count;
        
        
        int ans = 0,n=s.size(),i=0,j=0;
        map<char,int>mp;
        
        while(i<n && j<n)
        {
            while(j<n && (mp['a']==0 || mp['b']==0 || mp['c']==0))
            {
                mp[s[j]]++;
                j++;
            }
            
            while(mp['a'] && mp['b'] && mp['c'])
            {
                ans+= (n-j+1);
                mp[s[i]]--;
                i++;
            }
            //cout<<i<<" "<<j<<" "<<ans<<endl;
           
        }
        return ans;
    }
};