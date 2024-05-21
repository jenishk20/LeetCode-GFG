class Solution {
public:
    int dp[1001][1001];
    int recur(int i,int j,string &s,string &t){

        if(i<=0) return j;
        
        if(j<=0) return i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1]==t[j-1]){
            return recur(i-1,j-1,s,t);
        }
        else{
            int op1 = 1 + recur(i,j-1,s,t); //Insert
            int op2 = 1 + recur(i-1,j,s,t); // Delete
            int op3 = 1 + recur(i-1,j-1,s,t); // Replace
            
            return dp[i][j] = min({op1,op2,op3});
        }
        
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        // memset(dp,-1,sizeof dp);
        
        int i,j;
        
        
        for(i=0;i<=m;i++) dp[0][i] = i;
        for(j=0;j<=n;j++) dp[j][0] = j;
        dp[0][0] = 0;
        
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    
                    int op1 = 1 + dp[i][j-1]; //Insert
                    int op2 = 1 + dp[i-1][j]; // Delete
                    int op3 = 1 + dp[i-1][j-1]; // Replace

                    dp[i][j] = min({op1,op2,op3});
                }
            }
        }
        
        
        
        
        return dp[n][m];
    }
};