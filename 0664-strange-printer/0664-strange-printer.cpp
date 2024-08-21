class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int l = i+1;
        while(l<=j and s[i] == s[l]) l++;
        
        int op1 = 1 + solve(l,j,s);
        
        int op2 = 1e9;
        for(int p = l;p<=j;p++){
            if(s[p] == s[i]){
                int ans = solve(l,p-1,s) + solve(p,j,s);
                op2 = min(op2,ans);
            }
        }
        return dp[i][j] = min(op1,op2);
        
    }
    int strangePrinter(string s) {
        
        int n = s.size();
        memset(dp,-1,sizeof dp);
        return solve(0,n-1,s);
    }
};