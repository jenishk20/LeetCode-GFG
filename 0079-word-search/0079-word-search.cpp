class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool dfs(int i,int j,int st,vector<vector<char>>&board,
            string word){
    
        if(st == word.size()) return true;
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || word[st]!=board[i][j]) return false;
        
        
        char temp = board[i][j];
        board[i][j] = '0';
        
        for(int k=0;k<4;k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            
            if(dfs(nx,ny,st+1,board,word)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        int i,j,st = 0;
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(board[i][j] == word[st]){
                    if(dfs(i,j,st,board,word)) return true;
                }
            }
        }
        
        return false;
    }
};