class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        for(int i = 1;i<=1000;i++){
            
            auto itr = lower_bound(nums.begin(), nums.end(), i); 
            if (distance(itr, nums.end()) == i) return i; 
        }
        return -1;
    }
};