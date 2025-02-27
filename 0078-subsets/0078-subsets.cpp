class Solution {
public:
    void recur(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        recur(idx+1,nums,temp,ans);
        temp.pop_back();
        recur(idx+1,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        recur(0,nums,temp,ans);
        return ans;
    }
};