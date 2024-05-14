class Solution {
public:
    int dp[1001][1001];
    int recur(int i,int j,string &s,string &t){
        
        if(j<0){
            return 1;
        }
        
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            int op1 = recur(i-1,j,s,t);
            int op2 = recur(i-1,j-1,s,t);
            return dp[i][j] = op1 + op2;
        }
        
        return dp[i][j] =  recur(i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof dp);
        
        return recur(n-1,m-1,s,t);
    }
};