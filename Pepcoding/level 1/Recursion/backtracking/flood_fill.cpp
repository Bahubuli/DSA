#include<iostream>

#include<vector>

using namespace std;

void floodfill(vector < vector < int > > maze,int row,int col,vector < vector < bool > > visited,string psf)
{
    if(row<0||col<0|| row == maze.size() || col == maze[0].size() || maze[row][col]==1 ||visited[row][col]==true )
    {
               return;

    }
    if(row==maze.size()-1 && col == maze[0].size()-1)
    {
        cout<<psf<<endl;
        return;
    }

    visited[row][col]=true;

    floodfill(maze,row-1,col,visited,psf+"t");
    floodfill(maze,row,col-1,visited,psf+"l");
    floodfill(maze,row+1,col,visited,psf+"d");
    floodfill(maze,row,col+1,visited,psf+"r");


    visited[row][col]=false;

}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
     vector < vector < bool >> visited(n, vector <bool > (m,false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr,0,0,visited,"");
}
