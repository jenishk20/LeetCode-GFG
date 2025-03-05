class Solution {
public:
    int dp[301];
    unordered_set<string>st;
    bool solve(int idx,string &s){
        if(idx>=s.size()) return true;
        if(dp[idx] != -1) return dp[idx];
        if(st.count(s)) return true;

        for(int len = 1;len<=s.size();len++){
            string temp = s.substr(idx,len);
            if(st.count(temp) and solve(idx+len,s)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto it : wordDict) st.insert(it);
        memset(dp,-1,sizeof dp);
        return solve(0,s);  
    }
};