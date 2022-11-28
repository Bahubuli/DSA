class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int mprow[9][9]={0}, mpcol[9][9]={0}, mp3x3[9][9]={0};
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j]-'0'-1;
                    
                    int k = i/3*3+j/3;
                    if(mprow[i][num] || mpcol[j][num] || mp3x3[k][num])
                        return false;
                    
                    mprow[i][num] = mpcol[j][num] = mp3x3[k][num] = 1;
                }
            }
        }
        return true;
    }
};