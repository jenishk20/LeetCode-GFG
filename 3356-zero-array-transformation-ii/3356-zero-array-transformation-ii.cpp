class Solution {
public:
    bool check(int mid,vector<vector<int>>&queries,vector<int>&nums){
        
        int n = nums.size();
        vector<long long>lineSweep(n+1,0);
        
        for(int i=0;i<=mid;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int wt = queries[i][2];
            
            lineSweep[u]+=wt;
            lineSweep[v+1]-=wt;
            
        }
        
        for(int i=0;i<=n;i++){
            lineSweep[i] += (i-1>=0ll?lineSweep[i-1]:0ll);
        }

        
        for(int i=0;i<nums.size();i++){
            if(1ll*nums[i]-lineSweep[i]>0ll) return false;
        }
        
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int>sweepLine(n+1,0);
        
        int i;
        int st = 0;
        
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum == 0) return st;
        
        int l = 0;
        int r = queries.size()-1;
        int ans = -1;
        
        while(l<=r){
            int mid = (l+r)/2;
            
            if(check(mid,queries,nums)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
       
        return ans == -1 ? -1 : ans+1;
        
    }
};