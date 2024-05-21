class Solution {
public:
    int dp[1001][1001];
    int recur(int i,int j,string &s,string &t){
        
        if(i<0 and j<0) return 0;
        
        if(i<0) return j+1;
        
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
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
        
        memset(dp,-1,sizeof dp);
        return recur(n-1,m-1,word1,word2);
    }
};