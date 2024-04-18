class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int p = 0,i,j;
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 1){
                    p+=4;
                    
                    if(i-1>=0 and grid[i-1][j]==1){
                        p--;
                    }
                    if(i+1<n and grid[i+1][j]==1){
                        p--;
                    }
                    if(j-1>=0 and grid[i][j-1]==1){
                        p--;
                    }
                    if(j+1<m and grid[i][j+1]==1){
                        p--;
                    }
                }
            }
        }
        return p;
    }
};