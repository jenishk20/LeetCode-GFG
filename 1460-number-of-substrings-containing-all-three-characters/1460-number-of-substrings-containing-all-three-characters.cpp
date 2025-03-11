class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        map<char,int>ma;

        int i=0;
        int j=0;
        int cnt = 0;

        while(j<n){
            ma[s[j]]++;

            while(i<j and ma.size() == 3){
                cnt += n-j;
                // cout<<i<<" "<<j<<" "<<cnt<<endl;
                ma[s[i]]--;
                if(ma[s[i]] == 0) ma.erase(s[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};