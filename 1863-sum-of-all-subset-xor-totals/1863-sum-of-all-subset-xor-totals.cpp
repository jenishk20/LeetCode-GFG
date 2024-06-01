class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        
        int ori = 0;
        
        for(auto it : nums){
            ori |= it;
        }
        
        return ori * pow(2,n-1);
    }
};