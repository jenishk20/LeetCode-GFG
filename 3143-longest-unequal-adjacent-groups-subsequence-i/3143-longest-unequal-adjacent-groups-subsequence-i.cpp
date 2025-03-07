class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = words.size();
        vector<string>ans;
        vector<int>dp(n+1,1);
        int maxLength = 1;
        int ending = -1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i] != groups[j] and dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i]>maxLength){
                maxLength = dp[i];
                ending = i;
            }
        }
      
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;

        int exp = maxLength;
        for(int j=n-1;j>=0;j--){
            if(dp[j] == exp){
                exp--;
                ans.push_back(words[j]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};