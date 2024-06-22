class Solution {
public:
    
    int mod = 1e9+7;
    int dp[301][401];

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
           
        int i,j,k;
        
        dp[0][0] = 1;
        
        map<int, int> ma;
        for (auto it : requirements) {
            ma[it[0] + 1] = it[1];
        }
    
        for(i=1;i<=n;i++){
            for(j=0;j<=400;j++){
                for(k=0;k<i;k++){
                    if(j-k>=0){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k])%mod;
                    }
                }
            }
            if(ma.find(i)!=ma.end()){
                for(j=0;j<=400;j++){
                    if(j!=ma[i]){
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        
        int res = 0;
        
        for(i=0;i<=400;i++){
            res = (res+dp[n][i])%mod;    
        }
        
        return res;
        

    }
};