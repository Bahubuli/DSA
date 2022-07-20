#include<bits/stdc++.h>
using namespace std;

char *mystrtok(char *str,char delim)
{
    static char *input = NULL;
    if(str!=NULL)
        input = str;
    if(input==NULL)
        return NULL;

    char *token = new char[strlen(input) + 1];
    int i = 0;
    for(; input[i]!='\0';i++)
    {
        if(input[i]!=delim)
        {
            token[i] = input[i];
        }
        else
        {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }
    token[i] = '\0';
    input = NULL;
    return token;
}



int main()
{
    char str[100];
    cin.getline(str, 100);

    char *token = mystrtok(str, ' ');
    while(token!=NULL)
    {
        cout << token << endl;
        token = mystrtok(NULL, ' ');
    }
}
