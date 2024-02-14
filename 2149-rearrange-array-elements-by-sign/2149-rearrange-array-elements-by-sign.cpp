class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0,j=1;
        int n = nums.size();
        vector<int>ans(n);
        
        for(auto it:nums){
            if(it>0){
                ans[i] = it;
                i+=2;
            }
            else{
                ans[j] = it;
                j+=2;
            }
        }
        return ans;
    }
};