class Solution {
private:
    int dp[1001][1001];
    int recur(string &s, string &t, int i, int j) {
        if (i == 0 || j == 0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if (s[i - 1] == t[j - 1]) return 1 + recur(s, t, i - 1, j - 1);

        int op1 = recur(s, t, i - 1, j);
        int op2 = recur(s, t, i, j - 1);

        return dp[i][j] = max(op2, op1);
    }
    
public:
    int longestCommonSubsequence(string s,string t) {
        int n = s.size();
	    int m = t.size();
        // memset(dp,-1,sizeof dp);
        int i,j;
        
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                
                if(i==0 || j==0) dp[i][j] = 0;
                
                else if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
	    
    }
};