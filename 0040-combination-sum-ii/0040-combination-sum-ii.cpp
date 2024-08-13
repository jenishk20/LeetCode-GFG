class Solution {
public:
    void recur(int idx,vector<int>&candidates,int target,vector<int>temp,
    vector<vector<int>>&ans){

        if(target < 0) return;

        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx;i<candidates.size();i++){

            if(i>idx and candidates[i] == candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            recur(i+1,candidates,target-candidates[i],temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       
       vector<int>temp;
       sort(candidates.begin(),candidates.end());
       vector<vector<int>>ans;
       recur(0,candidates,target,temp,ans);
       return ans; 
        
    }
};