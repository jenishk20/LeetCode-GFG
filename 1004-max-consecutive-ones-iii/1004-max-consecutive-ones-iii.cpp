class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int ones = 0,zeroes = 0;
        int ans = 0;

        while(j<n){
            if(nums[j] == 1){
                ones++;
            }
            else{
                zeroes++;
                k--;
            }
            if(k>=0){
                ans = max(ans,ones + zeroes);
            }
            while(k<0){
                if(nums[i] == 1){
                    ones--;
                }
                else{
                    k++;
                    zeroes--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};