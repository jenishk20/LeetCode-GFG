class Solution {
public:
    void find(int idx,vector<int>& candidates, int target,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(idx==candidates.size())
        {
            if(target==0)
                ans.push_back(temp);
            return;
        }
        if(target>=candidates[idx])
        {
            temp.push_back(candidates[idx]);
            find(idx,candidates,target-candidates[idx],temp,ans);
            temp.pop_back();
        }
        find(idx+1,candidates,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        vector<vector<int>>ans;
        find(0,candidates,target,temp,ans);
        return ans;
    }
};