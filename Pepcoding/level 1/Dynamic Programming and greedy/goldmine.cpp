#include<bits/stdc++.h>
using namespace std;

//basic recursive solution
int goldmine(vector<vector<int>> maze,int r,int c)
{

    if(r>=maze.size() || c>=maze[0].size())
    return 0;

    else if(c== maze[0].size()-1)
    {
        return maze[r][c];
    }
    else
    {

  cout<<r<<" "<<c<<" "<<endl;
    int mx = -9999;

    int x = goldmine(maze,r-1,c+1);
    if(x>mx)
    mx=x;

    int y = goldmine(maze,r,c+1);
     if(y>mx)
    mx=y;

    int z = goldmine(maze,r+1,c+1);
     if(z>mx)
    mx=z;

int mx2=-999;

    if(c==0 && r==0)
    {
        for(int i=1;i<maze.size();i++)
        {
            int z1=goldmine(maze,r+i,c);
              if(z1>mx2)
                 mx2=z1;

        }
    }


    if(mx2>mx)
    return mx2;


    return  mx+maze[r][c];



    }







}

//dp

int goldminedp(vector<vector<int>> maze,int r,int c,vector<vector<int>> &dp)
{



    if(r>=maze.size() || c>=maze[0].size())
    return 0;

    else if(c== maze[0].size()-1)
    {
        return maze[r][c];
    }
    else
    {
        //cout<<" r "<<r<<" c "<<c<<endl;
        if(dp[r][c]!=maze[r][c])
        return dp[r][c];

  //cout<<r<<" "<<c<<" "<<endl;
    int mx = -9999;

    int x = goldminedp(maze,r-1,c+1,dp);
    if(x>mx)
    mx=x;

    int y = goldminedp(maze,r,c+1,dp);
     if(y>mx)
    mx=y;

    int z = goldminedp(maze,r+1,c+1,dp);
     if(z>mx)
    mx=z;

int mx2=-999;

    if(c==0 && r==0)
    {
        for(int i=1;i<maze.size();i++)
        {
            int z1=goldminedp(maze,r+i,c,dp);
              if(z1>mx2)
                 mx2=z1;

        }
    }


    if(mx2>mx)
    return mx2;

    dp[r][c]=mx+maze[r][c];
    return dp[r][c];



    }

}

//using memo.....


int main()
{
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    vector < vector < int >> dp(n, vector <int> (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j]= arr[i][j];

    //cout<<goldmine(arr,0,0)<<endl;

    cout<<goldminedp(arr,0,0,dp)<<endl;

    // for (int i = 0; i < n; i++)
    //  {   for (int j = 0; j < m; j++)
    //         cout<<dp[i][j]<<" ";

    //         cout<<"\n";
    //  }

}

// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1
