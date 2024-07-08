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
        
        // memset(dp,-1,sizeof dp);

        
  
        int res = 0;
        for(int i=2;i<=n;i++){
            res = (res + k)%i;
        }
        return 1 + res;
       
    }
};