class Solution {
public:
    bool check(int maxAmt, int stores,vector<int>&quantities){
        int reqStores = 0;
        for(auto it : quantities){
            reqStores += ceil((double)it/maxAmt);
        }
        return reqStores <= stores;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int maxi = *max_element(quantities.begin(),quantities.end());

        int low = 1;
        int high = maxi;
        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid,n,quantities)){
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