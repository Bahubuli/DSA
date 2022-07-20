#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    // char s1[20] = "hello brother !";
    // cout << s1 << endl;

    // char s2[] = "not array size given";
    // cout << s2 << endl;

    // char s3[] = {'B', 'A', 'T', '\0', 'M', 'A', 'N'};
    // //after \0 array ends
    // cout << s3 << endl;

    // char s4[] = {65, 66, 67, 68};
    // cout << s4 << endl;

    // char *s5 = " pointer array = i am vengeance ";
    // //use string s="hello"
    // cout << s5 << endl;

    //++++++++++++++++++++++++++++++++++++++++++++
    //taking string input

    //     char name[20];
    //     cout << "enter the name : ";
    //     cin >> name;

    //     cout << name << endl;
    //     //only first name will be printed not the surname

    //     cin.ignore();

    //     char fullname[20];
    //     cout << "again enter the name : ";

    //     cin.getline(fullname, 20);

    //     cout << fullname << endl;

    //#include<string> here string class has getline(cin,str) function

    // using string header file functions
    //+++++++++++++++++++++++++++++++++++++++++++++++

    // char s[50] = "hello world";
    // cout << strlen(s) << endl;

    // char s1[20]; //char * will not work
    // cout << "enter the string ";

    // //cin >> s; only print length of first word
    // cin.getline(s1, 20);

    // cout << strlen(s);

    // char s2[20] = " your self"; //can use string *s2 bacause of char *s1

    // strcat(s1, s2);

    // //strncat(s2,s3,5) only first 5 charactor will be added
    // cout << "concated string = " << s1;

    //+++++++++++++++++++++++++++++++++++++++++++++++

    // char s1[20] = "good";
    // char s2[20] = "";

    // strcpy(s2, s1);
    // //strncpy(s2,s1,2)
    // cout<< s2;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // char s1[20] = "programming";
    // char s2[10] = "m";
    // if (strstr(s1, s2) != NULL)
    //     cout << strstr(s1, s2); //gramming

    // //strrstr   occurance from rhs

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // char s1[20] = "Hello";
    // char s2[20] = "grllo";
    // //-1 0 +1
    // cout << strcmp(s1, s2) << endl;

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // char s1[10] = "235";
    // char s2[10] = "54.78";

    // long int x = strtol(s1, NULL, 10); //10 is base

    // float y = strtof(s2, NULL);

    // cout << x + 10 << " " << y + 10 << endl;

    // char s3[20] = "x=10;y=20;z=30"; //also known as key value string

    // //cout << strtok(s3, "=;"); // only print x

    // char *token = strtok(s3, "=;");

    // cout << "*token = " << token << endl;

    // while (token != NULL)
    // {
    //     cout << token << endl;
    //     token = strtok(NULL, "=;");
    // }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // String class functions

    // string str = "hello";

    // cout << str.length() << endl;

    // cout << str.capacity() << endl;

    // str.resize(40);
    // cout << str.capacity() << endl;

    // cout << str.max_size() << endl;

    // str.clear();
    // //str.empty() check if string is empty or not
    // cout << str.length() << endl;
    // cout << str.capacity() << endl;

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // string str = "hello";

    // cout << str.capacity() << endl;

    // str.append(" tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");

    // cout << str << endl;
    // cout << str.capacity() << endl;

    // str.clear();
    // str = "hello";

    // str.insert(3, "kk");
    // cout << str << endl;

    // str.insert(0, "fuck you", 5); // only first 5 letters are inserted
    // cout << str << endl;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // string str = "programming";

    // str.replace(3, 4, "XX");

    // cout << str << endl;

    // str.push_back('H');
    // cout << str << endl;

    // str.pop_back();
    // cout << str << endl;

    // string str2 = "language";

    // str.swap(str2);

    // cout
    //     << str << endl;
    // cout << str2 << endl;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // string s = "welcome";

    // char s2[10];

    // s.copy(s2, s.length());

    // s2[s.length()] = '\0';

    // //we need to add null charactor at end to avoid grabage values after welcome

    // cout << s2 << endl;

    // char s3[10];

    // s.copy(s3, 3);
    // s3[3] = '\0';

    // cout << s3 << endl;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // string s = "how are your hand";

    // cout << s.find("r") << endl;

    // //s.rfind will find from right side

    // cout << s.find_first_of("loin") << endl;

    // //will search for individual charactors

    // cout << s.substr(8, 4) << endl;

    // string s2 = "hello";
    // string s3 = "Hello";

    // cout << s2.compare(s3) << endl;

    // string s4 = s3 + " " + "world";

    // cout << s4 << endl;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    string s = "today";

    string::iterator it;

    for (it = s.begin(); it != s.end(); it++)
    {
        *it = *it - 32;
    }
    cout << s << endl;

    string::reverse_iterator rit;

    for (rit = s.rbegin(); rit != s.rend(); rit++)
    {
        cout << *rit;
    }
    cout << s << endl;
}