class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int n = arrays.size();
        int prevMin = arrays[0][0];
        int prevMax = arrays[0][arrays[0].size()-1];
        int res =0;
        
        for(int i=1;i<n;i++){
            int currMin = arrays[i][0];
            int currMax = arrays[i][arrays[i].size()-1];
            
            res = max({res,abs(currMin-prevMax),abs(currMax-prevMin)});
            
            prevMin = min(prevMin,currMin);
            prevMax = max(prevMax,currMax);
        }
        return res;
    }
};