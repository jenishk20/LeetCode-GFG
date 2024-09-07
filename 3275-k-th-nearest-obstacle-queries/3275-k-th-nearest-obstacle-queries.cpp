class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>pq;
        vector<int>ans;
        
        for(auto it : queries){
            pq.push(abs(it[0]) + abs(it[1]));
            if(pq.size()<k){
                ans.push_back(-1);
            }
            else if(pq.size()==k){
                ans.push_back(pq.top());
            }
            else{
                pq.pop();
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};