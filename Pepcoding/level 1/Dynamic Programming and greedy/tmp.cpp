#include <iostream>
#include <vector>
#include <string>
using namespace std;

static string code[] = {"?!", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> keypad(string number)
{
  if (number.size() == 0)
  {
    vector<string> base;
    base.push_back("");
    return base;
  }
  int ch = (int)number.at(0) - 48;

  string ros = number.substr(1);

  vector<string> rest_res = keypad(ros);
  vector<string> mres;
  string code_string = code[ch];

  for (auto x : code_string)
  {
    for (auto rres1 : rest_res)
    {
      mres.push_back(rres1 + x);

    }
  }
  return mres;
}

int main()
{

  string s;
  cin >> s;
  vector<string> ans = keypad(s);
  for (string x : ans)
  {
    cout << x << endl;
  }
  cout << "mc bc " << endl;
}
