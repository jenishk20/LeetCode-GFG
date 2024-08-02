class Solution {
public:
    int minSwaps(vector<int>& nums) {
    
        int cntOnes = 0;
        int i;
        int n = nums.size();
 
        for(i=0;i<n;i++){
            if(nums[i] == 1) cntOnes++;
        }

        if(cntOnes == 0 || cntOnes == n) return 0;

        int windowOnes = 0;
        int ans = 0;

        for(i=0;i<cntOnes;i++){
            windowOnes+=nums[i];
        }

        ans = max(ans,windowOnes);

        int r = i;

        for(i=0;i<n;i++){
            windowOnes -= nums[i];
            windowOnes += nums[r%n];
            ans = max(ans,windowOnes);
            r++;
        }

        return cntOnes - ans;

    }
};