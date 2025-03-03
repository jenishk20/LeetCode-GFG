class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int p1 = 1, p2 = 1;
        vector<int>res(n,1);

        for(int i=0;i<n;i++){
            res[i] *= p1;
            p1 *= nums[i];

            res[n-i-1] *= p2;
            p2 *= nums[n-i-1];
        }
        return res;

    }
};