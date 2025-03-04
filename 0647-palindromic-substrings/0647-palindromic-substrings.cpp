class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();

        int i,j;

        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int len = 1;len<=n;len++){
            for(i=0;i+len-1<n;i++){
                j = i+len-1;
                if(i == j) dp[i][j] = true;
                else if(i+1 == j) dp[i][j] = (s[i] == s[j]);
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]) cnt++;
            }
        }
        return cnt;
    }
};