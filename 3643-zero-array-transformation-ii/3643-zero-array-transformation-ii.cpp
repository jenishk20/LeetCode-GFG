class Solution {
public:
    bool check(int mid,vector<vector<int>>&queries,vector<int>&nums){
        int n = nums.size();
        int i;

        vector<int>pfx(n+1,0);
        for(int i=0;i<=mid;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int wt = queries[i][2];

            pfx[u] += wt;
            pfx[v+1] -= wt;
        }

        for(i=1;i<=n;i++){
            pfx[i] += pfx[i-1];
        }

        for(i=0;i<n;i++){
            if(pfx[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int k = queries.size();

        int low = 0;
        int high = k-1;
        int ans = 1e9;

        bool be = false;

        for(auto it : nums){
            if(it != 0) be = true;
        }

        if(be == false) return 0;

        while(low<=high){
            int mid = (low+high)/2;

            if(check(mid,queries,nums)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans == 1e9 ? -1 : ans+1;
    }
};