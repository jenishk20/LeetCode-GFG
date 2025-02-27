class Solution {
public:
    void recur(int i,int en,vector<int>&temp,vector<vector<int>>&ans,int currSum,
    vector<int>&candidates){

        if(i>=en){
            if(currSum == 0) ans.push_back(temp);
            return;
        }

        if(currSum >= candidates[i]){
            currSum -= candidates[i];
            temp.push_back(candidates[i]);
            recur(i,en,temp,ans,currSum,candidates);
            currSum += candidates[i];
            temp.pop_back();
        }
        recur(i+1,en,temp,ans,currSum,candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n = candidates.size();
        vector<int>temp;
        recur(0,n,temp,ans,target,candidates);
        return ans;
    }
};