class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        vector<int>sweepLine(n+1,0);
        
        for(auto it : queries){
            int u = it[0];
            int v = it[1];
            
            sweepLine[u]++;
            sweepLine[v+1]--;
        }
        
        for(int i=0;i<=n;i++){
            sweepLine[i] += (i-1>=0 ? sweepLine[i-1] : 0);
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]-sweepLine[i]>0) return false; 
        }
        return true;
    }
};