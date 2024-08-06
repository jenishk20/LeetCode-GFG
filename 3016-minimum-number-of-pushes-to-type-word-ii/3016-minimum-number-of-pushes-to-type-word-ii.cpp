class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<pair<char,int>>ve;
        map<char,int>ma;
        map<char,int>positionOfLetter;

        int ans = 0;
        int st = 0;
        int inc = 1;

        for(auto it : word){
            ma[it]++;
        }

        for(auto it : ma){
             ve.push_back({it.first,it.second});
        }

        sort(ve.begin(),ve.end(),[](pair<char,int>&a,pair<char,int>&b){
            return a.second > b.second;
        });
        
        for(auto it : ve){
            if(st == 8){
                st = 0;
                inc++;
            }
            positionOfLetter[it.first] = inc;
            st++;
        }

        for(auto it : positionOfLetter){
           ans += it.second * ma[it.first];
        }
        return ans;
    }
};