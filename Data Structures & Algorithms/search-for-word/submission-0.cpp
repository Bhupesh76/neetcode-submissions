class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &board,string word,int delrow[],int delcol[],int k)
    {
        if(k==word.size()) return true;
        int n = board.size();
        int m = board[0].size();

        vis[r][c] = 1;

        for(int i=0; i<4; i++)
        {
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[k])
            {
                if(dfs(nrow,ncol,vis,board,word,delrow,delcol,k+1))
                {
                    return true;
                }
            }
        }
        vis[r][c] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(word[0] == board[i][j])
                {
                    if(dfs(i,j,vis,board,word,delrow,delcol,1))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
