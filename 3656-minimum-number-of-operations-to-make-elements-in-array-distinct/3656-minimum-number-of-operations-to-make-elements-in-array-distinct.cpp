class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        set<int>se;

        for(int i=n-1;i>=0;i--){
            if(se.count(nums[i])){
                return ceil((double)(i+1)/3);
            }
            se.insert(nums[i]);
        }
        return 0;
    }
};