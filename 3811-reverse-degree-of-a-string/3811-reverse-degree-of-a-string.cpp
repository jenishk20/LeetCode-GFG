class Solution {
public:
    int reverseDegree(string s) {
        
        int n = s.size();
        long long ans = 0;

        for(int i=0;i<n;i++){
            ans = ans + ('z' - s[i] + 1) * 1ll * (i+1);
        }
        return ans;
    }
};