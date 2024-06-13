class Solution {
public:
    int dp[2000][6000];
    int recur(int i,int n,vector<int>&rewardValues,int x){
        
        if(i>=n) return 0;
        
        int op1 = 0;
        int op2 = 0;
        if(dp[i][x]!=-1){
            return dp[i][x];
        }
        
        if(x<rewardValues[i]){
            op1 = rewardValues[i] + recur(i+1,n,rewardValues,x+rewardValues[i]);
            op2 = recur(i+1,n,rewardValues,x);
        }
        else{
            op1 = recur(i+1,n,rewardValues,x);
        }
        return dp[i][x] = max(op1,op2);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        
        int n = rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        memset(dp,-1,sizeof dp);
        return recur(0,n,rewardValues,0);
    
       
    }
};