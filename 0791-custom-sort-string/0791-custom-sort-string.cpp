class Solution {
public:
    string customSortString(string order, string s) {
        
        map<char,int>ma;
        
        int st = 1;
        
        for(auto i:order)
            ma[i] = st++;
        
       sort(s.begin(),s.end(),[&](char c1,char c2){
            return ma[c1]<ma[c2];
        });
        
        return s;
    }
};