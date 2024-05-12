class Solution {
public:

    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();
        
        int i;
        int ans = -1e4;
        vector<int>dp(n,0);
        
        dp[n-1] = energy[n-1];
        
        for(i=n-2;i>=0;i--){
            
            if(i+k<n){
                dp[i] = dp[i+k] + energy[i];
            }
            else{
                dp[i] = energy[i];
            }
        }
        
        for(i=0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        
        return ans;
       
    }
};