class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int i;
        int cnt = 0;
        
        int maxTillNow = nums[0];
        
        for(i=1;i<n;i++){
            if(nums[i] <= maxTillNow)   
            {
                cnt += (maxTillNow - nums[i] + 1);
                nums[i] = maxTillNow + 1;
                
            }
            maxTillNow = max(maxTillNow,nums[i]);
            
        }
        return cnt;
    }
};