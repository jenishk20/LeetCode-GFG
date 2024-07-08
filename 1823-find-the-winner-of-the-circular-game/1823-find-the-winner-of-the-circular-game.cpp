class Solution {
public:
    int dp[1001];
    int recur(int n,int k){
        if(n==1) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int idx = recur(n-1,k);
        idx = (idx + k)%n;
        return dp[n] = idx;
    }
    int findTheWinner(int n, int k) {
        
        memset(dp,-1,sizeof dp);
        return 1 + recur(n,k);
    }
};