class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        int i = 0;

        vector<int>pfx(n+1,0);

        for(auto it : shifts){
            int u = it[0];
            int v = it[1];
            int dir = it[2];
            if(dir == 1){
                pfx[u]++;
                pfx[v+1]--;
            }
            else{
                pfx[u]--;
                pfx[v+1]++;
            }
        }

        for(i=1;i<n;i++){
            pfx[i] += pfx[i-1];
        }
        
        for(i=0;i<n;i++){

            int st = pfx[i];

            if(st > 0){
                s[i] = (s[i]-'a' + pfx[i]%26)%26 + 'a';
            }
            else if(st<0){
                s[i] = (s[i]-'a' + pfx[i]%26 + 26)%26 + 'a';
            }
        }
        return s;
    }
};