class Solution {
public:
    bool check(int mid,vector<int>&nums,int maxOpr){
        int req = 0;

        for(auto it : nums){
            if(it<=mid) continue;
            req += it/mid;
            if(it%mid == 0) req--;
        }
        
        return req<=maxOpr;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;
            
            if(check(mid,nums,maxOperations)){
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