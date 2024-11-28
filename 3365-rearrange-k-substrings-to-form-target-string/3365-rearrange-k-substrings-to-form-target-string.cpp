class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        
        int n = s.size();
        map<string,int>req;
        
        string curr = "";
        
        for(int i=0;i<n;i+=n/k){
            string temp = t.substr(i,n/k);
            req[temp]++;
        }
        
        for(int i=0;i<n;i+=n/k){
            string temp = s.substr(i,n/k);
            if(req.find(temp) == req.end()) return false;
            
            req[temp]--;
        }
        
        for(auto it : req){
            if(it.second != 0) return false;
        }
        
        return true;
    }
};