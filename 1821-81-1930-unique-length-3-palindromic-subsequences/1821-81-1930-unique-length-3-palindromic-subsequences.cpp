class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char,vector<int>>ma;

        for(int i=0;i<n;i++){
            ma[s[i]].push_back(i);
        }
        
        int cnt = 0;

        for(auto it : ma){
            vector<int>pos = it.second;
            if(pos.size()<2) continue;

            int first = pos[0];
            int second = pos.back();
            
            set<char>se;
            for(int j = first+1;j<second;j++){
                se.insert(s[j]);
            }
            cnt += se.size();
        }

        return cnt;
    }
};