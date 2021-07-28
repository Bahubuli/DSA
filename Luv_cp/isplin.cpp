#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int hsh[N][28];


int main()
{


     freopen("i.txt", "r", stdin);
     freopen("o.txt", "w", stdout);

/*
     int t;
     cin >> t;
     while(t--)
     {
         int n, q;
         cin >> n >> q;
         string s;
         cin >> s;
         while(q--)
         {
             int l, r;
             cin >> l >> r;
             int hsh[26];
             for(int i=0;i<26;i++)
             {
                 hsh[i] = 0;
             }
             l--;
             r--;
             for(int i=l;i<=r;i++)
             {
                 hsh[s[i] - 'a']++;
             }
             int oddct = 0;
             for(int i=0;i<26;i++)
             {
                 if(hsh[i]%2!=0)
                     oddct++;
             }
             if(oddct>1)
                 cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
            }
         }
     }
     */
     int t;
     cin >> t;
     while (t--)
     {

         int n, q;
         cin >> n >> q;
         string s;
         cin >> s;
         for (int i = 1; i <= n; i++)
         {
             for (int j = 0; j < 26; j++)
             {
                 hsh[i][j] = 0;
             }
         }
         for (int i = 1; i <= n; i++)
         {
             hsh[i][s[i - 1] - 'a']++;
         }
         cout << "after hashing" << endl;

         for (int i = 1; i <= n; i++)
         {
             for (int j = 0; j < 26; j++)
             {
                 cout << hsh[i][j] << " ";
             }
             cout << endl;
         }
         cout << "after prefix sum" << endl;

         for (int i = 1; i <= n; i++)
         {
             for (int j = 0; j < 26; j++)
             {
                 hsh[i][j] += hsh[i - 1][j];
                 cout << hsh[i][j] << " ";
             }
             cout << endl;
         }

         while (q--)
         {
             int l, r;
             cin >> l >> r;

             int oddcount = 0;
             for (int i = 0; i < 26; i++)
             {
                 int charct = hsh[r][i] - hsh[l - 1][i];
                 if (charct % 2 != 0)
                     oddcount++;
             }
             if (oddcount > 1)
                 cout << "NO" << endl;
             else
             {
                 cout << "YES" << endl;
             }
         }
     }
}
