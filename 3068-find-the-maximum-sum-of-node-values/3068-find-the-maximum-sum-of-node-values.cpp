class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        vector<int>delta;
        long long ans = 0;
        
        int n = nums.size();
        
        int i;
        
        for(i=0;i<n;i++){
            delta.push_back((nums[i]^k)-nums[i]);
            ans+=nums[i];
        }

        
        sort(delta.begin(),delta.end());
                
    
        for(int i=n-1;i>=0;i--){
            if(i-1>=0){
                int canAdd = delta[i] + delta[i-1];
                if(canAdd<=0) break;
                i--;
                ans+=canAdd;
            }
        }
        return ans;
    }
};