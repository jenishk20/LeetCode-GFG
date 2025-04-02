class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;

        int n = nums.size();
        vector<long long>dp(n,0);
        
        long long maxSoFar = 0;

        for(int i=0;i<n;i++){
            dp[i] = max(i-1>=0?dp[i-1]:0, maxSoFar - nums[i]);
            maxSoFar = max(maxSoFar,nums[i]*1ll);
        }

        for(int i=2;i<n;i++){
            ans = max(ans,dp[i-1]*1ll*nums[i]);
        }

        return ans;
    }
};