class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        
        int i,j,k,l;
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                
                int maxi = -1;
                if(i+2<n and j+2<m){
                for(k = i;k<i+3;k++){
                    for(l = j;l<j+3;l++){
                        
                        maxi = max(maxi,grid[k][l]);
                    }
                }
                    ans[i][j] = maxi;
                
            }
                
            }
        }
        
        return ans;
    }
};