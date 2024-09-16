class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        map<int,int>ma;
        for(auto it : nums) ma[it]++;
        
        vector<int>ans;
        for(auto it : ma) if(it.second == 2) ans.push_back(it.first);
        
        return ans;
    }
};