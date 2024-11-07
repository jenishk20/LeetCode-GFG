class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if(m>n) return {};
        vector<int>ans;

        int i=0;
        int j=0;
        vector<int>freqS(26,0);
        vector<int>freqP(26,0);
        
        for(i=0;i<m;i++){
            freqP[p[i]-'a']++;
        }

        i=0;
        while(j<n){
            freqS[s[j]-'a']++;

            if(j-i+1 > m){
                freqS[s[i]-'a']--;
                i++;                
            }
            if(j-i+1 == m){
                if(freqS == freqP){
                    ans.push_back(i);
                }
            }
            j++;
        }
        return ans;
    }
};