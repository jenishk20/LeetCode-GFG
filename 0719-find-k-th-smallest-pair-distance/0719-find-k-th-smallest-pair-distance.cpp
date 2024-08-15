class Solution {
public:

    int countPairs(int mid,vector<int>&nums){

        int i = 0;
        int j = 1;
        int n = nums.size();

        int cnt = 0;

        while(j<n){
            if(nums[j]-nums[i]<=mid){
                cnt += j-i;
            }
            else{
                while(i<j and nums[j]-nums[i]>mid){
                    i++;
                }
                continue;
            }
            j++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int i,j;    

        sort(nums.begin(),nums.end());

        int low = 0;
        int high = nums[n-1];
        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;

            int pairs = countPairs(mid,nums);
            if(pairs >= k){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};