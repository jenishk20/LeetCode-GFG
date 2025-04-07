class Solution {
public:
    int dp[201][20001];
    bool checkIfSubsetSumExists(int idx,vector<int>&nums,int sum){
        if(idx>=nums.size()) return sum == 0;
        if(sum == 0) return 1;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool op1 = false,op2 = false;
        if(sum>=nums[idx]){
            op1 = checkIfSubsetSumExists(idx+1,nums,sum - nums[idx]);
        }
        op2 = checkIfSubsetSumExists(idx+1,nums,sum);
        return dp[idx][sum] = op1 or op2;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum&1) return false;
        return checkIfSubsetSumExists(0,nums,sum/2);
    }
};