class Solution {
public:
    int dp[5002][4001];
    int recur(int idx,int tNo,vector<int>&prices,int n){
        if(idx >= n) return 0;
        
        if(dp[idx][tNo]!=-1) return dp[idx][tNo];
        
        if(tNo%2==0){
            int op1 = -prices[idx] + recur(idx+1,tNo+1,prices,n);
            int op2 = recur(idx+1,tNo,prices,n);
            return dp[idx][tNo] = max(op2,op1);
        }
        else{
            int op1 = prices[idx] + recur(idx+2,tNo+1,prices,n);
            int op2 = recur(idx+1,tNo,prices,n);
            return dp[idx][tNo] = max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        memset(dp,-1,sizeof dp);
        return recur(0,0,prices,n);
    }
};