class Solution {
public:
    int dp[13][10001];
    int recur(int idx,vector<int>&coins,int amount){
        
        if(idx==0){
            
            if(amount%coins[idx]==0) return amount/coins[idx];
            
            return 1e9;
        }
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        
        int op1 = recur(idx-1,coins,amount);
        int op2 = 1e9;
        
        if(amount>=coins[idx]){
            op2 = 1 + recur(idx,coins,amount-coins[idx]);
        }
        
        return dp[idx][amount] = min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        // memset(dp,-1,sizeof dp);
        
        int i,j;
        
        for(i=0;i<n;i++){
            for(j=0;j<=amount;j++){
                
                if(i==0){
                    if(j%coins[i]==0){
                        dp[i][j] = j/coins[i];
                    }
                    else{
                        dp[i][j] = 1e9;
                    }
                }
                else{
                    
                    int op1 = dp[i-1][j];
                    int op2 = 1e9;
                    
                    if(j>=coins[i]){
                        op2 = 1 + dp[i][j-coins[i]];
                    }
                    
                    dp[i][j] = min(op1,op2);
                }
            }
        }
        
        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
        // int ans = recur(n-1,coins,amount);
        // return ans == 1e9 ? -1 : ans;
    }
};