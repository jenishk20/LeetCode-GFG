class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int minSoFar = prices[0];
        int ans = -1e9;

        for(int i=0;i<n;i++){
            ans = max(ans,prices[i] - minSoFar);
            minSoFar = min(minSoFar,prices[i]);    
        }
        return ans;
    }
};