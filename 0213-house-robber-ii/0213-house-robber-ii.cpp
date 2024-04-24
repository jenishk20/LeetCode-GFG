class Solution {
public:
    
    int recur(int idx,int st,int en,vector<int>&nums,vector<int>&dp){
        
        if(idx<st) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
            
        int op1 = (idx>=2) ? nums[idx] + recur(idx-2,st,en,nums,dp) : nums[idx];
        int op2 = recur(idx-1,st,en,nums,dp);
        
        return dp[idx] = max(op1,op2);
        
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,-1),dp1(n,-1);
        
        if(n==1) return nums[0];
        
        int op1 = recur(n-1,1,n,nums,dp);
        
        // dp.resize(n,-1);
        
        int op2 = recur(n-2,0,n-1,nums,dp1);
        
        return max(op1,op2);
    }
};