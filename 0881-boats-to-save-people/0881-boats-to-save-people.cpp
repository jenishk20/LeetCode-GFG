class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        
        sort(nums.begin(),nums.end());
        
        int ans = 0;
        int n = nums.size();
        
        int i = 0;
        int j = n-1;
        
        int cnt = 0;
        vector<int>vis(n,0);
        
        while(i<j){
            
            if(nums[i] + nums[j]<=limit){
                cnt++;
                vis[i] = 1;
                vis[j] = 1;
                i++;
                j--;
              
            }
            else if(nums[i]+nums[j]>limit){
                j--;
            }
        }
        
        for(i=0;i<n;i++){
            if(!vis[i]) cnt++;
        }
        
        return cnt;
    }
};