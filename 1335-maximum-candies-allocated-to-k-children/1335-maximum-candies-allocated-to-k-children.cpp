class Solution {
public:
    bool check(int mid,vector<int>&candies,long long k){
        long long canGet = 0;
        for(auto it : candies){
            canGet += it/mid;
        }
        return canGet >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;

            if(check(mid,candies,k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};