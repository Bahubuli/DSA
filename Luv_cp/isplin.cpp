#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int hsh[N][26];

void edtio()
{
    int t;
    cin >> t;
    while(t--)
    {



        int n, q;
        cin >> n >> q;
        //initialize hash arry to zero for each test case
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hsh[j][i] =0;
            }
        }


        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            hsh[i+1][s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << hsh[j][i] << " ";
            }
            cout << endl;
        }

        cout << "++++++++++++++++" << endl;
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<=n;j++)
            {
                hsh[j][i] += hsh[j - 1][i];
                cout << hsh[j][i] << " ";
            }
            cout << endl;
        }

                while (q--)
                {
                    int l, r;
                    cin >> l >> r;

                    int oddcount = 0;
                    for(int i=0;i<26;i++)
                    {
                        int charct = hsh[r][i] - hsh[l - 1][i];
                        if(charct%2!=0)
                            oddcount++;
                    }
                    if(oddcount>1)
                        cout << "NO" << endl;
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
    }
}



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
     edtio();
}
