class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long long maxReach = 0;
        
        int i=0;
        int patches = 0;
        int sz = nums.size();
        
        while(maxReach<n){
            
            if(i<sz and nums[i]<=maxReach+1){
                
                maxReach += nums[i];
                i++;
            }
            else{
                patches++;
                maxReach += (maxReach+1);
            }
        }
        
        return patches;
    }
};