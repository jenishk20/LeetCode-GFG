class Solution {
public:
 typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;

        map<ll,ll>ma;

        int i;
        int n = nums.size();
        ll sum = 0;

        for(i=0;i<k;i++){
            ma[nums[i]]++;
            sum += nums[i];
        }
        if(ma.size() == k) ans = sum;

        for(i=k;i<n;i++){
            sum -= nums[i-k];
            sum += nums[i];
            ma[nums[i]]++;
            if(ma[nums[i-k]] == 1) ma.erase(nums[i-k]);
            else ma[nums[i-k]]--;

            if(ma.size() == k) ans = max(ans,sum);
        }
        return ans;
    }
};