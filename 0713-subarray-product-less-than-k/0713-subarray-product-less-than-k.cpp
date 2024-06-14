class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        int currentProd = 1;
        int ans = 0;
        
        while(j<n){
            
            currentProd *= nums[j];
            while(i<=j and currentProd >= k){
                    currentProd /= nums[i];
                    i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};