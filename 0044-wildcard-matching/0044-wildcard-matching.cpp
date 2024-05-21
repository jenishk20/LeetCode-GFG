class Solution {
public:
    
    int dp[2001][2001];
    bool recur(int i,int j,string &s,string &p){
        
        if(i==0 and j==0) return true;
        
        if(i>0 and j==0) return false;
 
        if(i==0 and j>0) {
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] =  recur(i-1,j-1,s,p);
        if(p[j-1] == '*') return dp[i][j] = recur(i-1,j,s,p) || recur(i,j-1,s,p);
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        vector<int>curr(m+1),prev(m+1);
        
        int i,j;
        
        prev[0] = 1;
    
        for(j=1;j<=m;j++){
            bool be = true;
              for(int k=1;k<=j;k++){
                if(p[k-1]!='*') {
                    be = false;
                    // dp[0][j] = 0;
                }
            }
            prev[j] = be;
        }
        
        for(i=1;i<=n;i++){
            curr[0] = 0;
            
            for(j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j] = prev[j] || curr[j-1];
                }
                else{
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        
        
        return prev[m];
    }
};