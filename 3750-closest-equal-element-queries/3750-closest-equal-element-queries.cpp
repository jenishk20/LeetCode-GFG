class Solution {
public:
    int find(int i, int j, int n){
        int temp = abs(i-j);
        return min(temp, n - temp);
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int>ans;
        for(int i = 0; i<queries.size(); i++){
            vector<int>&indices = mp[nums[queries[i]]];
            if(indices.size()==1) ans.push_back(-1);
            else{
                int ans_Ind = INT_MAX; 
                int ind = lower_bound(indices.begin(), indices.end(), queries[i]) - indices.begin();
                int m = indices.size();
                if(ind != 0){
                    int prev = indices[ind - 1];
                    ans_Ind = min(ans_Ind, find(queries[i], prev,n));
                }
                else{
                    int last = indices[m-1];
                    ans_Ind= min(ans_Ind, find(queries[i], last, n));
                }

                if(ind + 1 != m){
                    int next = indices[ind + 1];
                    ans_Ind = min(ans_Ind, find(queries[i], next, n));
                }
                else{
                    int next = indices[0];
                    ans_Ind = min(ans_Ind, find(queries[i], next, n));
                }
                ans.push_back(ans_Ind);
            }
        }
        return ans;
    }
};