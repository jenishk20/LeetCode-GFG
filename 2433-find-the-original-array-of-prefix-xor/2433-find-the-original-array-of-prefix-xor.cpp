class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        vector<int>ans;
        
        int n = pref.size();
        int xori = 0;
        
        for(auto it : pref)
            xori^=it;
        
        ans.push_back(pref[0]);
        xori = pref[0];
        
        for(int i=1;i<pref.size();i++){
            
            int kiskeSaathYehAyega = xori^pref[i];
            ans.push_back(kiskeSaathYehAyega);
            xori^=kiskeSaathYehAyega;
        }
        
        return ans;
    }
};