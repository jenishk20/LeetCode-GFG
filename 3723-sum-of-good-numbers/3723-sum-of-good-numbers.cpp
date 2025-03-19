class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i-k>=0 and i+k<n){
                if(nums[i] > nums[i-k] and nums[i]>nums[i+k]) sum += nums[i];
            }
            else if(i-k>=0){
                if(nums[i] > nums[i-k]) sum += nums[i];
            }
            else if(i+k<n){
                if(nums[i]> nums[i+k]) sum += nums[i];
            }
            else if(i-k<0 and i+k>=n){
                sum += nums[i];
            }
        }
        return sum;
    }
};