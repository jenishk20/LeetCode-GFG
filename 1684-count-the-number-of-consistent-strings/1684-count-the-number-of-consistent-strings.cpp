class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        vector<int>vis(26,0);
        
        for(auto it : allowed) vis[it-'a']=1;
            
        int cnt = 0;
        
        for(auto it : words){
            bool be = true;
            for(auto it2 : it){
                if(!vis[it2-'a']){
                    be = false;
                    break;
                }
            }
            if(be) cnt++;
        }
        return cnt;
    }
};