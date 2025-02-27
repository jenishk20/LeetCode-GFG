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
        int n= nums.size();
        vector<vector<int>>ans;

        for(int i=0;i<pow(2,n);i++){
            vector<int>temp;

            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};