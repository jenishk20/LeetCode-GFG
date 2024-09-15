class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int,int>ma;
        
        int n = s.size();
        int mask = 0;
        int ans = 0;
        ma[mask] = -1;
        
        for(int i=0;i<n;i++){
            if(s[i] == 'a') mask = mask ^ (1<<0);
            if(s[i] == 'e') mask = mask ^ (1<<1);
            if(s[i] == 'i') mask = mask ^ (1<<2);
            if(s[i] == 'o') mask = mask ^ (1<<3);
            if(s[i] == 'u') mask = mask ^ (1<<4);
            
            if(ma.find(mask)!=ma.end()){
                ans = max(ans,i-ma[mask]);
            }
            else{
                ma[mask] = i;
            }
        }
        return ans;
    }
};