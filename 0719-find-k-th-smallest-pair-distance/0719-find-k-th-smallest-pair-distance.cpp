class Solution {
public:
int findPairs(int mid,vector<int>&nums){
    int j=1;
    int i=0;
    int cnt = 0;
    int n = nums.size();

    while(j<n){
        if(nums[j]-nums[i]<=mid){
            cnt+=(j-i);
        }
        else{
            while(i<j and nums[j]-nums[i]>mid){
                i++;
            }
            cnt += (j-i);
        }
        j++;
    }
    return cnt;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        int low = 0;
        int high = nums[n-1];
        while(low<=high){
            int mid = (low+high)/2;

            int noOfPairs = findPairs(mid,nums);
            cout<<mid<<" "<<noOfPairs<<endl;
            if(noOfPairs>=k){
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