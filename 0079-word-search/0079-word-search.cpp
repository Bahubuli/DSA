class Solution {
public:
    int dx[4]  = {0,0,1,-1};
    int dy[4]  = {1,-1,0,0};
    
    bool dfs(vector<vector<char>>&board,int i,int j,string &word,int idx)
    {
        int n = board.size(),m=board[0].size();
        if(idx==word.size()) return true;
        
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[idx]) return false;
        
        char c= board[i][j];
        board[i][j] = '.';
        
        for(int k =0;k<4;k++)
            if(dfs(board,i+dx[k],j+dy[k],word,idx+1)) return true;
        
        board[i][j] = c;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                    if(dfs(board,i,j,word,0)) return true;
            }
        }
        
        return false;
    }
};