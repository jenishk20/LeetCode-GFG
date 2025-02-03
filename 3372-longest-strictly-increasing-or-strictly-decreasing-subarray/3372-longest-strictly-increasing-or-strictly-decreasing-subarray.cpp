class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0, cnt2 = 0;
        int ans = 1;

        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                cnt1++;
            }
            else{
                ans = max(ans,cnt1+1);
                cnt1 = 0;
            }
            if(nums[i]<nums[i+1]){
                cnt2++;
            }
            else{
                ans = max(ans,cnt2+1);
                cnt2 = 0;
            }
        }
        ans = max({ans,cnt1+1,cnt2+1});
        return ans;
    }
};