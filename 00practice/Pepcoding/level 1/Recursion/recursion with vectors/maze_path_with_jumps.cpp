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
    vector<string> res ={};
   

    if(sr==dr && sc==dc )
    {
         vector<string> res ={""};
    return res;
    }

        for(int i=1;i+sc<=dc;i++)
            {
                vector<string> cpath = getmazepaths(sr,sc+i,dr,dc);
               for(string s:cpath)
                    {
                        res.push_back("h"+to_string(i)+s);
                        

                        
    
                    }

            }
        

        for(int i=1;i+sr<=dr;i++)
        {
        vector<string> rpath = getmazepaths(sr+i,sc,dr,dc);
        
            for(string s:rpath)
                    {
                        res.push_back("c"+to_string(i)+s);
                        

                        
    
                    }


        }
      
    
            for(int i=1;(i+sr<=dr && i+sc<=dc);i++)
                {
                    vector<string> dpath = getmazepaths(sr+i,sc+i,dr,dc);
                    for(string s:dpath)
                    {
                        res.push_back("d"+to_string(i)+s);
                        

                        
    
                    }

                }
        

   

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
    
