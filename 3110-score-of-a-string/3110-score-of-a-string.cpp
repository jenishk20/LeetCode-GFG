class Solution {
public:
    int scoreOfString(string s) {
        
        int ans =0;
        for(int i=0;i<s.size()-1;i++){
            
            int p = s[i];
            int p1 = s[i+1];
            
            ans+=abs(p1-p);
        }
        return ans;
    }
};