class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>se(nums.begin(),nums.end());

        
        int ans = 0;
        for(int it : se){
            int prev = it-1;
            if(se.count(prev)) continue;
            int st = it;
            while(se.count(it+1)){
                it++;
            }
            ans = max(ans,it-st+1);
        }
        return ans;
    }
};