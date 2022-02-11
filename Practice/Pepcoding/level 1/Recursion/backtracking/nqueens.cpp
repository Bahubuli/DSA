#include<bits/stdc++.h>
using namespace std;

bool isqueensafe(vector<vector<int>> board,int r,int c)
{
  int i=0,j=0;

  i=r-1;j=c;
  while(i>=0)
  {
      if(board[i][j]==1)
          return false;
      i--;
  }
  i=r-1;j=c-1;
  while(i>=0 && j>=0)
  {
      if(board[i][j]==1)
          return false;

      i--;
      j--;
  }

   i=r-1;j=c+1;
  while(i>=0 && j<board[0].size())
  {
      if(board[i][j]==1)
          return false;

      i--;
      j++;
  }

    return true;
}

void nqueens(vector<vector<int>> board,string asf,int row)
{
    if(row==board[0].size())
    {
        cout<<asf<<endl;
        return;
    }

    for(int col=0;col<board[0].size();col++)
    {
        if(isqueensafe(board,row,col))
        {
        board[row][col]=1;
        nqueens(board,asf+to_string(row)+"-"+to_string(col)+",",row+1);
        board[row][col]=0;
        }

    }


}

int main()
{

    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int> (n,0));

    nqueens(board,"",0);

}
