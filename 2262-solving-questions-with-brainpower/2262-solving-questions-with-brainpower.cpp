class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<long long>dp(n+1,0);
        long long ans = 0;

        for(int i=n-1;i>=0;i--){
            long long canGet = questions[i][0];
            long long toSkip = questions[i][1];
            if(i+toSkip+1<n){
                dp[i] = max(dp[i+1], canGet + dp[i+toSkip+1]);
            }
            else{
                dp[i] = max(dp[i+1],canGet);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};