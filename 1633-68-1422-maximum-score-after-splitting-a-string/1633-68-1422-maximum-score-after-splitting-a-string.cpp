class Solution {
public:
    int maxScore(string s) {
        
        int n = s.size();
        vector<int>pfx(n+1,0);
        vector<int>sfx(n+1,0);

        int i;
        pfx[0] = (s[0] == '0') ? 1 : 0;
       

        for(i=1;i<n;i++){
            if(s[i] == '0') pfx[i] = pfx[i-1] + 1;
            else pfx[i] = pfx[i-1];
        }

        for(i=n-2;i>=0;i--){
            if(s[i+1] == '1') sfx[i] = sfx[i+1] + 1;
            else sfx[i] = sfx[i+1];
        }

        int ans = 0;
        for(i=0;i<n-1;i++){
    
            ans = max(ans,pfx[i] + sfx[i]);
        }

        return ans;
    }
};