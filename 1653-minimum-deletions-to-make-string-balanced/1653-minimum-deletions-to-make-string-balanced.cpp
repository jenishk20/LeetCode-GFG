class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        vector<int>pfxb(n,0),sfxa(n,0);
        
        int i;
        for(i=1;i<n;i++){
            pfxb[i] = pfxb[i-1] + (s[i-1]=='b');
        }
        
        for(i=n-2;i>=0;i--){
            sfxa[i] = sfxa[i+1] + (s[i+1] == 'a');
        }
        
        int ans = 1e8;
        
        for(i=0;i<n;i++){
            ans = min(ans,pfxb[i] + sfxa[i]);
        }
        
        return ans;
    }
};