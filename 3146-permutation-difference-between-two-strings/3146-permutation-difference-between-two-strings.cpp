class Solution {
public:
    int findPermutationDifference(string s, string t) {
        
        map<char,int>ma;
        
        int n = s.size(),i;
        
        for(i=0;i<n;i++){
            ma[t[i]] = i;
        }
        
        int cnt = 0;
        for(i=0;i<n;i++){
            cnt+=abs(i-ma[s[i]]);
        }
        
        return cnt;
        
        
    }
};