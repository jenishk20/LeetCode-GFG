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
        
        vector<int>curr(m+1,0),prev(m+1);
        
        
        int i,j;

        for(j=0;j<=m;j++) prev[j] = j;

        
        for(i=1;i<=n;i++){
            curr[0] = i;
            for(j=1;j<=m;j++){
                
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    
                    int op1 = 1 + curr[j-1]; //Insert
                    int op2 = 1 + prev[j]; // Delete
                    int op3 = 1 + prev[j-1]; // Replace

                    curr[j] = min({op1,op2,op3});
                }
            }
            prev = curr;
        }
        
        return prev[m];
    }
};