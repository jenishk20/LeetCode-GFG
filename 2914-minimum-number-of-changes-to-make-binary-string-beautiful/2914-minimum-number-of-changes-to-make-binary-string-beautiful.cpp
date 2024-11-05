class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int i;
        int ans = 0;
        for(i=0;i<n;i++){

            char curr = s[i];
            int cnt = 1;

            while(i+1<n and s[i+1] == curr){
                cnt++;
                i++;
            }
            if(cnt&1){
                i++;
                ans++;
            }
        }
        return ans;
    }
};