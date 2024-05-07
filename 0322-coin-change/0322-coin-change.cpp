class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<int>prev(amount+1);
        
        int i,j;
        
        for(i=0;i<n;i++){
            
            vector<int>curr(amount+1);
            for(j=0;j<=amount;j++){
                
                if(i==0){
                    if(j%coins[i]==0){
                        curr[j] = j/coins[i];
                    }
                    else{
                        curr[j] = 1e9;
                    }
                }
                else{
                    
                    int op1 = prev[j];
                    int op2 = 1e9;
                    
                    if(j>=coins[i]){
                        op2 = 1 + curr[j-coins[i]];
                    }
                    
                    curr[j] = min(op1,op2);
                }
            }
            prev = curr;
        }
        
        return prev[amount] == 1e9 ? -1 : prev[amount];
        // int ans = recur(n-1,coins,amount);
        // return ans == 1e9 ? -1 : ans;
    }
};