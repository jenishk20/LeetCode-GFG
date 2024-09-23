class Solution {
public:
    vector<int>dp;

    int solve(string& s, unordered_map<string, int>&mp, int index)
    {
        if (index >= s.size()) return 0;
        
        string currStr = "";
        int minExtra = s.size();
        if(dp[index] != -1) return dp[index];
        
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            //currStr will be a string from (index to cutIdx)
            
            //if string not in dictionary, we have to delete as they are extra chars
            int currExtra = (mp.count(currStr))? 0 : currStr.size();
            int nextExtra = solve(s, mp, cutIdx + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        
        unordered_map<string, int>mp;
        for (string& word : dictionary) mp[word]++;
        
        dp.resize(s.size()+1,-1);
        int ans = solve(s, mp, 0);
        return ans;
    }
};