class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>ma;
        for(auto i:s) ma[i]++;
        
        for(int i=0;i<s.size();i++){
            if(ma[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};