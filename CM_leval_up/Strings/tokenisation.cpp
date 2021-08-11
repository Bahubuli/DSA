#include<bits/stdc++.h>
using namespace std;

int main()
{


//using sstream class
/*
 string in;
    getline(cin, in);
    stringstream ss(in);

    string token;
    vector<string> tokens;
    while(getline(ss,token,' '))
    {
        tokens.push_back(token);
    }

    for(auto s:tokens)
        cout << s << endl;
        */
//using strtok
char inp[10000];
cin.getline(inp, 1000);

// cout << strtok(inp, " ") << endl;
// cout << strtok(NULL, " ") << endl;
// cout << strtok(NULL, " ") << endl;
// cout << strtok(NULL, " ") << endl;

// this will give us the first 4 words after tokenisation

char *token = strtok(inp, " ");

while(token!=NULL)
{
    cout << token << endl;
    token = strtok(NULL, " ");

}

}
