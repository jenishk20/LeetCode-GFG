class Solution {
public:
    int dp[1001][1001];
    int recur(int i,int j,vector<vector<int>>&fruits,int movesLeft,int n){

        if(i<0 or j<0 or i>=n or j>=n) return -1e9;
        if(movesLeft == 0){
            if(i==n-1 and j == n-1) return 0;
            return -1e9;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int op1 = fruits[i][j] + recur(i-1,j+1,fruits,movesLeft-1,n);
        int op2 = fruits[i][j] + recur(i,j+1,fruits,movesLeft-1,n);
        int op3 = fruits[i][j] + recur(i+1,j+1,fruits,movesLeft-1,n);
        return dp[i][j] = max({op1,op2,op3});
    }

    int recur1(int i,int j,vector<vector<int>>&fruits,int movesLeft,int n){

        
        if(i<0 or j<0 or i>=n or j>=n) return -1e9;

        if(i==n-1 and j==n-1){
            if(movesLeft == 0) return 0;
            return -1e9;
        }
        if(movesLeft == 0){
            if(i==n-1 and j == n-1) return 0;
            return -1e9;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
      
        int op1 = fruits[i][j] + recur1(i+1,j-1,fruits,movesLeft-1,n);
        int op2 = fruits[i][j] + recur1(i+1,j,fruits,movesLeft-1,n);
        int op3 = fruits[i][j] + recur1(i+1,j+1,fruits,movesLeft-1,n);
       
        return dp[i][j] = max({op1,op2,op3});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {

        int n = fruits.size();
      
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        
        memset(dp,-1,sizeof dp);
        int op1 = recur(n-1,0,fruits,n-1,n);
        int i,j;
        memset(dp,-1,sizeof dp);
        int op2 = recur1(0,n-1,fruits,n-1,n);

        return ans + op1 + op2;
    }
};