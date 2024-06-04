class Solution {
public:
    int longestPalindrome(string s) {
        
        int n = s.size();
        map<char,int>ma;
        
        for(auto it : s){
            ma[it]++;
        }
        
        int cnt=0;
        bool first = false;
        
        for(auto it : ma){
            if(it.second&1){
                if(!first){
                    cnt+=it.second;
                    first = true;
                }        
                else{
                    cnt+=it.second-1;
                }
            }
            else{
                cnt+=it.second;
            }
        }
        
        return cnt;
        
    }
};