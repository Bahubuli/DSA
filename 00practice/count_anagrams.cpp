#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int search2(string pat, string txt)
    {
        int n = txt.length(), k = pat.length();
        vector<int> m1(26, 0), m2(26, 0);
        int i = 0, count = 0;

        for (i = 0; i < k; i++)
        {
            m1[pat[i] - 'a']++;
            m2[txt[i] - 'a']++;
        }
        if (m1 == m2)
            count++;

        for (i = k; i < n; i++)
        {
            m2[txt[i] - 'a']++;
            m2[txt[i - k] - 'a']--;

            if (m1 == m2)
            {
                count++;
            }
        }
        return count;
    }

    int search(string pat, string txt)
    {
        unordered_map<char, int> mp;
        int n = pat.length(), m = txt.length();
        for (int i = 0; i < n; i++)
            mp[pat[i]]++;
        int count = mp.size();
        int ans = 0, i = 0, j = 0;
        while (j < m)
        {
            
            if (mp[txt[j++]]-- == 1)
                count--;
            if (count == 0)
                ans++;
            if (j >= n)
                if (mp[txt[i++]]++ == 0)
                    count++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
