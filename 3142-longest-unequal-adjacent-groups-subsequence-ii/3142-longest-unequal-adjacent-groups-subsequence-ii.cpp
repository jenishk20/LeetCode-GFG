class Solution {
public:

    bool findHamming(string &s, string &t){
        if(s.size() != t.size()) return false;

        int diff = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] != t[i]) diff++;
        }
        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string>ans;
        vector<int>dp(n+1,1);
        int maxLength = 1;
        int ending = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i] != groups[j] and dp[i] < dp[j] + 1 and findHamming(words[i],words[j])){
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i]>maxLength){
                maxLength = dp[i];
                ending = i;
            }
        }
    
        string prev = words[ending];
        int exp = maxLength-1;
        ans.push_back(prev);
        int prevIdx = ending;


        for(int j=ending-1;j>=0;j--){
            string curr = words[j];
            if(dp[j] == exp and groups[prevIdx]!=groups[j] and findHamming(curr,prev)){
                prev = curr;
                exp--;
                prevIdx = j;
                ans.push_back(curr);
            }
        }
         
        reverse(ans.begin(),ans.end());
        return ans;
    }
};