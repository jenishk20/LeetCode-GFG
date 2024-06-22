class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0,m = 0,r = 0;
        int odd = 0;
        int res = 0;
        
        while(r<n){
            
            if(nums[r]&1) odd++;
            
            while(odd>k){
                if(nums[l]&1) odd--;
                l++;
                m = l;
            }
            
            if(odd == k){
                while(nums[m]%2==0){
                    m++;
                }
                
                res += (m-l+1);
            }
            
            r++;
        }
        return res;
    }
};