class Solution {
public:
    int dp[100001][4][4];
    int mod = 1e9 + 7;
    int recur(int n,int totalAbsence,int totalConsDays){
        
       
        
        if(totalAbsence==2 || totalConsDays==3){
            return 0;
        }
         
        if(n==0) return 1;
        
        int op1 = 0,op2 = 0,op3 = 0;
        int ans = 0;
        
        if(dp[n][totalAbsence][totalConsDays]!=-1) 
            return dp[n][totalAbsence][totalConsDays]%mod;
        
        op1 = recur(n-1,totalAbsence+1,0)%mod;
        op2 = recur(n-1,totalAbsence,0)%mod;
        op3 = recur(n-1,totalAbsence,totalConsDays+1)%mod;
        
        ans = (ans+op1)%mod;
        ans = (ans+op2)%mod;
        ans = (ans+op3)%mod;
        ans%=mod;
        
        return dp[n][totalAbsence][totalConsDays] = ans;
        
        
    }
    int checkRecord(int n) {
        
        char curr = ' ';
        memset(dp,-1,sizeof dp);
        return recur(n,0,0)%mod;
    }
};