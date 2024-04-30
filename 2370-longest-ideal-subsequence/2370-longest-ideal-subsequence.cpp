class Solution {
public:
    
    int recur(int currIdx,int prevTookChar,string &s,int k,int n,
              int dp[][150]){
        
        if(currIdx>=n) return 0;
        
        int op1 = -1e8,op2 = -1e8;
        
        if(dp[currIdx][prevTookChar]!=-1) return dp[currIdx][prevTookChar];
        
        if(prevTookChar == 0 || abs(s[currIdx]-prevTookChar)<=k){
            op1 = 1 + recur(currIdx+1,s[currIdx],s,k,n,dp);
            op2 = recur(currIdx+1,prevTookChar,s,k,n,dp);
        }
        else{
            op2 = recur(currIdx+1,prevTookChar,s,k,n,dp);
        }
        
        return dp[currIdx][prevTookChar] = max(op1,op2);
    }
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        
        int dp[100001+1][150];
        memset(dp,-1,sizeof dp);
        return recur(0,0,s,k,n,dp);
    }
};