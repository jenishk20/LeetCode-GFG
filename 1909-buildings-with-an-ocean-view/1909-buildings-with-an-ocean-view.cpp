class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        int maxiTillNow = 0;
        vector<int>ans;
        
        for(int i=heights.size()-1;i>=0;i--){
            if(heights[i]>maxiTillNow){
                ans.push_back(i);
                maxiTillNow = heights[i];
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};