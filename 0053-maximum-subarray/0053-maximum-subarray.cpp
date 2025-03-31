class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>pfxSum(n+1,0);
        pfxSum[0] = nums[0];
        int minSoFar = 0;
        int ans = -1e9;

        for(int i = 1;i<n;i++){
            pfxSum[i] = pfxSum[i-1] + nums[i];
        }

        for(int i=0;i<n;i++){
            int endingHereMaxSum = pfxSum[i] - minSoFar;
            minSoFar = min(minSoFar,pfxSum[i]);
            ans = max(ans,endingHereMaxSum);
        }
        return ans;
    }
};