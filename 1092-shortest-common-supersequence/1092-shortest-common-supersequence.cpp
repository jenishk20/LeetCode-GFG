class Solution {
public:
    int recur(string &s,string &t,int i,int j){
        if(i<=0 || j<=0) return 0;
        
        if(s[i-1] == t[j-1]) return 1 + recur(s,t,i-1,j-1);
        
        int op1 = recur(s,t,i-1,j);
        int op2 = recur(s,t,i,j-1);
        
        return max(op1,op2);
    }
    string shortestCommonSupersequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        int i,j;
      
        
        int dp[n+1][m+1];
        
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                
                if(i==0 || j==0) dp[i][j] = 0;
                else{
                    
                    if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                    else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        
        i = n;
        j = m;
        
        string lcs = "";
        
        while(i>0 && j>0){
            
            if(s[i-1] == t[j-1]){
                
                lcs+=s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        
        
        reverse(lcs.begin(),lcs.end());

        i=0,j=0;
        int k = 0;
        
        string res = "";
        
        while(i<n && j<m && k<lcs.size()){
            
            if(s[i]!=lcs[k] && t[j]!=lcs[k]){
                res+=s[i];
                res+=t[j];
                i++;
                j++;
            }
            else if(s[i]==lcs[k] && t[j]!=lcs[k]){
                res+=t[j];
                j++;
            }
            else if(s[i]!=lcs[k] && t[j]==lcs[k]){
                res+=s[i];
                i++;
            }
            else{
                res+=lcs[k];
                k++;
                i++;
                j++;
            }
        }
        
        while(i<n){
            res+=s[i++];
        }
        while(j<m){
            res+=t[j++];
        }
        
        return res;
    }
};