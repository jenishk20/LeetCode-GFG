class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int i,j,k;
        
        for(i=0;i<n;i++){
            if(grid[i][0]!=1){
                for(j=0;j<m;j++){
                    grid[i][j]^=1;
                }
            }
        }
        
        for(i=0;i<m;i++){
            int cone = 0,czero = 0;
            for(j=0;j<n;j++){
                
                if(grid[j][i])
                    cone++;
                else czero++;
            }
            
            if(czero>cone){
                for(j=0;j<n;j++){
                    grid[j][i]^=1;
                }
            }
        }
        
        int ans = 0;
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                
                ans+=(grid[i][j]?(1<<(m-j-1)):0);
            }
        }
        return ans;
    }
};