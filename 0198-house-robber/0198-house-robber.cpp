class Solution {
public:
    int recur(int idx,vector<int>&nums,vector<int>&dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int op1 = nums[idx] + recur(idx-2,nums,dp);
        int op2 =  recur(idx-1,nums,dp);
        
        return dp[idx] = max(op2,op1);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,-1);
        
        dp[0] = nums[0];
        
        for(int i=1;i<n;i++){
            
            int op1 = (i>=2)?dp[i-2] + nums[i]:nums[i];
            int op2 = dp[i-1];
            
            dp[i] = max(op1,op2);
        }
        return dp[n-1];
        
        
        
        
//         return recur(n-1,nums,dp);
    }
};