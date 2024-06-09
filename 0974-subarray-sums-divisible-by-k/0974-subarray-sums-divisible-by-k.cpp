class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int,int>ma;
        
        int sum = 0;
        ma[sum] = 1;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            
            int rem = sum%k;
            
            if(rem < 0) rem += k;
            
            ans += ma[rem];
            
            ma[rem]++;
        }
        
        return ans;
        
    }
};