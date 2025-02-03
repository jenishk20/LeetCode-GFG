class Solution {
public:
    int maxDifference(string s) {
        
        map<char,int>ma;
        for(auto it : s) ma[it]++;

        int m1 = 0, m2 = 0, m3 = 1e9, m4 = 1e9;
        vector<int>odd,even;
        for(auto it : ma){
            if(it.second&1) odd.push_back(it.second);
            else even.push_back(it.second);
        }

        int ans = -1e9;
        for(auto it : odd){
            for(auto it1 : even)
            ans = max(ans,it-it1);
        }

        return ans;

    }
};