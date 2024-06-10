class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int cnt = 0;
        vector<int>tt = heights;
        sort(tt.begin(),tt.end());
        
        int n = heights.size();
        
        for(int i=0;i<n;i++){
            cnt+=(heights[i] != tt[i]);
            
        }
        return cnt;
        
    }
};