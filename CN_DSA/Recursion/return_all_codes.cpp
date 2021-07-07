#include<bits/stdc++.h>
using namespace std;

vector<string> allcodes(string s,vector<string> sinp,string pf)
{
    //taking first 1 char
    if(s.size()==0)
    {
        vector<string> bsec;
        bsec.push_back(pf);
        return bsec;
    }

        char ch1 = s[0];
        ch1 = 96 + ch1 - '0';


        vector<string>res1 = allcodes(s.substr(1), sinp, pf + ch1);
        vector<string> fin;
        for (string s : res1)
        {
            fin.push_back(s);
        }

        //taking first 2 char

        if (s.length() >= 2)
        {
            int ch12 = stoi(s.substr(0, 2));

            vector<string> res2;

            if (ch12 <= 26 && ch12>9)
            {

                char ch12v = 96 + ch12;
                if(s.size()==2)
                res2 = allcodes("", sinp, pf + ch12v);
                else
                 res2 = allcodes(s.substr(2), sinp, pf + ch12v);
            }
            else
            {
                if (s.size() == 2)
                     res2 = allcodes("", sinp, pf);
                else
                     res2 = allcodes(s.substr(2), sinp, pf);
            }
            for (string s : res2)
            {
                fin.push_back(s);
            }
        }
        return fin;
}

int main()
        {

            freopen("i.txt", "r", stdin);
            freopen("o.txt", "w", stdout);

            string s = "1123";
            vector<string> sinp;
            vector<string> res = allcodes(s, sinp, "");

            for (string s : res)
                cout << s << endl;

}
