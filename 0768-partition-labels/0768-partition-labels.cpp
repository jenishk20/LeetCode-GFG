class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size();
        map<char,pair<int,int>>ma;
        
        int i;
        for(i=0;i<n;i++){
            if(ma.find(s[i]) == ma.end()){
                ma[s[i]] = {i,i};
            }
            else{
                ma[s[i]] = {ma[s[i]].first,i};
            }
        }

        vector<int>ans;
        int st = 0;
        int prevSt = ma[s[0]].first;
        int prevEn = ma[s[0]].second;
        int currSt, currEn;
        for(i=1;i<n;i++){
            currSt = ma[s[i]].first;
            currEn = ma[s[i]].second;

            if(currSt > prevEn){
                ans.push_back(currSt - prevSt);
                prevSt = currSt;
                prevEn = currEn;
            }
            else{
                prevEn = max(currEn,prevEn);
            }
        }
        ans.push_back(n - prevSt);
        return ans;
    }
};