class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        int j=0,i=0;
        
        while(i<n and j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return m-j;
    }
};