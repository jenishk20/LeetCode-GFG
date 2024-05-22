class Solution {
public:
    int dp[1001][1001];
    
    int recur(int i,int cap,int tNo,vector<int>&prices,int n){
        
        if(i==n || tNo == 2*cap) return 0;
        
        if(dp[i][tNo]!=-1) return dp[i][tNo];
        
        if(tNo%2==0){
            int op1 = -prices[i] + recur(i+1,cap,tNo+1,prices,n);
            int op2 = recur(i+1,cap,tNo,prices,n);
            return dp[i][tNo] = max(op1,op2);
        }
        else{
            int op1 = +prices[i] + recur(i+1,cap,tNo+1,prices,n);
            int op2 = recur(i+1,cap,tNo,prices,n);
            return dp[i][tNo] = max(op1,op2);  
        }
    }
    int maxProfit(int k, vector<int>& prices) {
                
        int n = prices.size();
        memset(dp,-1,sizeof dp);
        
        return recur(0,k,0,prices,n);
        
        
    }
};