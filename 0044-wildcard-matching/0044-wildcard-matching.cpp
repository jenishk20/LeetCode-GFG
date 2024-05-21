class Solution {
public:
    
    int dp[2001][2001];
    bool recur(int i,int j,string &s,string &p){
        if(j<0) return i<0;
        
        if(i<0) {
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] =  recur(i-1,j-1,s,p);
        if(p[j] == '*') return dp[i][j] = recur(i-1,j,s,p) || recur(i,j-1,s,p);
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        memset(dp,-1,sizeof dp);
        return recur(n-1,m-1,s,p);
    }
};