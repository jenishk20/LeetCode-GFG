class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int n = s1.size();
        int i;
        int cnt = 0;
        vector<int>temp;

        for(i=0;i<n;i++){
            if(s1[i] != s2[i]){
                temp.push_back(i);
                cnt++;
            }
        }
        if(cnt == 0) return true;
        if(cnt != 2) return false;

        return s1[temp[0]] == s2[temp[1]] and s1[temp[1]] == s2[temp[0]];
    }
};