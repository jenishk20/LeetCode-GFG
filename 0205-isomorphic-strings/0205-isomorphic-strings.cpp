class Solution {
public:
    bool isIsomorphic(string s, string t) {
    
        int n = s.size();
        int m = t.size();
        
        if(n!=m) return false;
        
        map<char,char>ma,ma1;
        
        for(int i=0;i<n;i++){
            
            if(ma.find(s[i])!=ma.end() && ma[s[i]]!=t[i] ||
               ma1.find(t[i])!=ma1.end() && ma1[t[i]]!=s[i])
                return false;
            
            ma[s[i]] = t[i];
            ma1[t[i]] = s[i];
        }
        
        return true;
    }
};