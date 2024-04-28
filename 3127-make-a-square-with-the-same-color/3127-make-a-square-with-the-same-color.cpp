class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int i,j;
        
        
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                map<char,int>ma;
                if(j+1<m && i+1<n){
                    
                    ma[grid[i][j]]++;
                    ma[grid[i+1][j]]++;
                    ma[grid[i][j+1]]++;
                    ma[grid[i+1][j+1]]++;
                    
                    if(ma['B']==1 || ma['W']==1 || ma['B']==0 || ma['W']==0) return 1;
                }
                
            }
        }
        return 0;
    }
};