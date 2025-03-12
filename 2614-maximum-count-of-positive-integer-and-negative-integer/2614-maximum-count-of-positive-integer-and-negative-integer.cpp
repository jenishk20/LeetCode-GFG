class Solution {
public:
    int lowerBound(vector<int>&nums){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<0){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>&nums){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<=0){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        int idxLb = lowerBound(nums);
        int idxUp = upperBound(nums);
        int k = nums.size();
        return max(idxLb,k-idxUp);
    }
};