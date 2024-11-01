class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int i;

        string res = "";
        for(i=0;i<n;i++){
            int ans = 1;
            char ch = s[i];
            while(i+1<n and s[i] == s[i+1]){
                i++;
                ans++;
            }
            if(ans>=3){
                res += string(2,ch);
            }
            else{
                res += string(ans,ch);
            }
        }
        return res;
    }
};