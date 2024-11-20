class Solution {
public:
    int takeCharacters(string s, int k) {
        int ca = 0;
        int cb = 0;
        int cc = 0;
        int n = s.size();
        int ans = 0;

        int i = 0;
        int j = 0;

        for(auto it : s){
            if(it == 'a') ca++;
            else if(it == 'b') cb++;
            else cc++;
        }

        if(ca<k or cb<k or cc<k) return -1;

        ca-=k;
        cb-=k;
        cc-=k;

        while(j<n){
            if(s[j] == 'a') ca--;
            else if(s[j] == 'b') cb--;
            else cc--;
            while(ca<0 or cb<0 or cc<0){
                if(s[i] == 'a') ca++;
                else if(s[i] == 'b') cb++;
                else cc++;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return n-ans;
    }
};