class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] < k) return -1;
        }

        set<int>se;
        for(int i=0;i<n;i++){
            if(nums[i] > k){
                se.insert(nums[i]);
            }
        }
        return se.size();
    }
};