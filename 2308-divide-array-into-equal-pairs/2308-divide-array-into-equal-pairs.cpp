class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        map<int,int>ma;
        for(auto it : nums) ma[it]++;
        
        for(auto it : ma){
            if(it.second&1) return false;
        }
        return true;
    }
};