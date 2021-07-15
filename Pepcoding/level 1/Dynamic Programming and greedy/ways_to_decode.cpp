#include<bits/stdc++.h>
using namespace std;


int main()
{

  string s;
  cin >> s;

  vector<int> dp(s.length());
  dp[0] = 1;

  for(int i=1;i<dp.size();i++)
  {
    if(s[i-1]=='0' && s[i]=='0')
    {
      dp[i] = 0;
    }
    else if (s[i - 1] == '0' && s[i] != '0')
    {
      dp[i] = dp[i - 1];
    }
    else if (s[i - 1] != '0' && s[i] == '0')
    {
      if(s[i-1]=='1' || s[i-1]=='2')
      {
        dp[i] = dp[i - 2];
      }
      else
      {
        dp[i] = 0;
      }

    }
    else
    {
      if(stoi(s.substr(i-1,2))<=26)
      {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
      else
      {
        dp[i] = dp[i - 1];
      }

    }
}
