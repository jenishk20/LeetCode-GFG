class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int sum = 0;
        int maxi = 0;

        for(int i=0;i<nums.size();i++){
            if(i+1<nums.size() and nums[i]>=nums[i+1]){
                sum += nums[i];
                maxi = max(maxi,sum);
                sum = 0;
                continue;
            }
            sum += nums[i];
        }
        return max(sum,maxi);
    }
};