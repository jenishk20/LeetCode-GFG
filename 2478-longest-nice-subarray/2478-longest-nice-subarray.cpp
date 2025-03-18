class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int currentBits = 0;

        int i=0;
        int j=0;
        int ans = 1;

        while(j<n){
            while((currentBits & nums[j])!=0){
                currentBits ^= nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            currentBits |= nums[j];
            j++;
        }
        return ans;
    }
};