class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int i;
        vector<int>pfx(n,0);
        pfx[0] = nums[0];

        for(i=1;i<n;i++){
            pfx[i] = pfx[i-1] + nums[i];
        }

        int minSoFar = 0;
        int ans = -1e9;

        for(i=0;i<n;i++){
            int bestEndingHere = pfx[i] - minSoFar;
            ans = max(ans,bestEndingHere);
            minSoFar = min(minSoFar,pfx[i]);
        }
        return ans;
    }
};