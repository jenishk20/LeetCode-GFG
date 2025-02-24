class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(1){
            int sz = s.size();
            if(sz == 2) return s[0] == s[1];
            int i=0;
            for(i=0;i<s.size()-1;i++){
                s[i] = (s[i]-'0' + s[i+1]-'0')%10 + '0';
            }
            s.erase(s.begin()+i);
        }
        return false;
    }
};