class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefx = 1,suffix = 1;
        int i;
        int ans = -1e9;

        for(i=0;i<n;i++){
            if(prefx == 0) prefx = 1;
            if(suffix == 0) suffix = 1;

            prefx *= nums[i];
            suffix *= nums[n-i-1];
            ans = max({ans,prefx,suffix});
        }
        return ans;

    }
};