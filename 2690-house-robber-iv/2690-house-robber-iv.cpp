class Solution {
public:
    bool check(int mid,vector<int>&nums,int k){
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                ans++;
                i++;
            }
        }
        return ans>=k;
       



    }
    int minCapability(vector<int>& nums, int k) {
        
        int n = nums.size();
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;

            if(check(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};