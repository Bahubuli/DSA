#include<bits/stdc++.h>
using namespace std;

//basic recursive solution
int mincostmaze(vector<vector<int>> maze,int r,int c)
{


    if(r>=maze[0].size() || c>=maze[0].size())
    return 9999;

    else if( r==maze[0].size()-1 && c== maze[0].size()-1)
    {
        return maze[r][c];
    }
    else
    {

  //cout<<r<<" "<<c<<" "<<endl;


    int mn=9999;





    int near = mincostmaze(maze,r+1,c);
    if(near<mn)
    mn=near;

    near = mincostmaze(maze,r,c+1);
    if(near<mn)
    mn=near;



    return maze[r][c]+mn;
    }


}

//dp

int mincostmazedp(vector<vector<int>> maze,int r,int c,vector<vector<int>> &dp)
{


    if(r>=maze[0].size() || c>=maze[0].size())
    return 9999;

    else if( r==maze.size()-1 && c== maze[0].size()-1)
    {
        return maze[r][c];
    }
    else
    {

    //cout<<r<<" "<<c<<" "<<endl;
    if(dp[r][c]!=maze[r][c])
    return dp[r][c];


    int mn=9999;





    int near = mincostmazedp(maze,r+1,c,dp);
    if(near<mn)
    mn=near;

    near = mincostmazedp(maze,r,c+1,dp);
    if(near<mn)
    mn=near;

    dp[r][c]=maze[r][c]+mn;

    return dp[r][c];
    }


}


int main() {
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

    //cout<<mincostmaze(arr,0,0)<<endl;

    cout<<mincostmazedp(arr,0,0,dp)<<endl;


}

// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1
