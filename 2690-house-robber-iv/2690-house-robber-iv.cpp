class Solution {
public:
    bool check(int mid,vector<int>&nums,int k){
        int n = nums.size();
        
        vector<int>temp;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                temp.push_back(i);
            }
        }

        if(temp.size() < k) return false;
        vector<int>dp(temp.size(),1);

        for(int i=1;i<temp.size();i++){
            if(temp[i] > temp[i-1] + 1){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = max(dp[i],(i-2>=0)?dp[i-2]+1:0);
            }
        }
        return dp[temp.size()-1]>=k;
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