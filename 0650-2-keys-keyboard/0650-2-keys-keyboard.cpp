class Solution {
public:
    int dp[1001][1001];
    int recur(int currA,int currC,int n){
        if(currA == n) return 0;
        if(currA > n) return 1e9;
        
        if(dp[currA][currC]!=-1) return dp[currA][currC];
        
        int op1 = 2 + recur(currA+currA,currA,n);
        int op2 = 1 + recur(currA+currC,currC,n);
        
        return dp[currA][currC] = min(op1,op2);
    }
    int minSteps(int n) {
        
        if(n==1) return 0;
        memset(dp,-1,sizeof dp);
        
        int currA = 1;
        int currC = 1;
        
        return 1 + recur(currA,currC,n);
    }
};