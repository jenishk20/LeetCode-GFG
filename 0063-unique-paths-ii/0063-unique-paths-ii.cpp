/*
    Recursion :
    
    TC : O (2^(n*m))
    SC : O (n+m) 

*/

// class Solution {
// public:
    
//     int recur(int i,int j,int n,int m,vector<vector<int>>&obstacleGrid){
        
//         if(i<0 || j<0) return 0;
        
//         if(i==0 && j==0 && obstacleGrid[i][j]==0) return 1;
        
//         if(obstacleGrid[i][j]!=1){
            
//             int op1 = recur(i-1,j,n,m,obstacleGrid);
//             int op2 = recur(i,j-1,n,m,obstacleGrid);
            
//             return op1 + op2;
//         }
        
//         return 0;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
        
//         return recur(n-1,m-1,n,m,obstacleGrid);
//     }
// };



/*
    Memoization :
    
    TC : O (n*m)
    SC : O (n+m) + O (n*m) 

*/

class Solution {
public:
    
    int recur(int i,int j,int n,int m,vector<vector<int>>&obstacleGrid,
             vector<vector<int>>&dp){
        
        if(i<0 || j<0) return 0;
        
        if(i==0 && j==0 && obstacleGrid[i][j]==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(obstacleGrid[i][j]!=1){
            
            int op1 = recur(i-1,j,n,m,obstacleGrid,dp);
            int op2 = recur(i,j-1,n,m,obstacleGrid,dp);
            
            return dp[i][j] = op1 + op2;
        }
        
        return dp[i][j]=0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return recur(n-1,m-1,n,m,obstacleGrid,dp);
    }
};