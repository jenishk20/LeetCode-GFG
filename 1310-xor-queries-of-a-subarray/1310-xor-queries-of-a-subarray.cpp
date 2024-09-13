class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int>pfxXor(n);
        vector<int>ans;
        
        pfxXor[0] = arr[0];
        
        for(int i=1;i<n;i++){
            pfxXor[i] = pfxXor[i-1]^arr[i];
        }
        
        for(auto it : queries){
            int u = it[0];
            int v = it[1];
            
            if(u == 0) ans.push_back(pfxXor[v]);
            else ans.push_back(pfxXor[v]^pfxXor[u-1]);
        }
        
        return ans;
    }
};