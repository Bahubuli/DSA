#include <iostream>
#include <vector>
using namespace std;
void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

vector<string> getmazepaths(int sr, int sc, int dr, int dc)
{

    if (sr == dr && sc == dc)
    {
        vector<string> hres = {""};
        return hres;
    }
    vector<string> hres = {};
    vector<string> cres = {};

    if (sr < dr)
    {

        hres = getmazepaths(sr + 1, sc, dr, dc);
    }

    if (sc < dc)
    {

        cres = getmazepaths(sr, sc + 1, dr, dc);
    }


    vector<string>res = {};
    for(string path:cres)
    res.push_back("h"+path);

    for(string path:hres)
    res.push_back("v"+path);

    return res;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int sr, sc, dr, dc;
    cin >> dr >> dc;

    vector<string> ans = getmazepaths(1, 1, dr, dc);
    display(ans);
}
