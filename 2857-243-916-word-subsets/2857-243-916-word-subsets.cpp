class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxOcc(26,0);
        int n = words1.size();
        int m = words2.size();
        vector<string>ans;

        int i,j;

        for(i=0;i<m;i++){
            string curr = words2[i];
            vector<int>currOcc(26,0);
            for(auto it : curr){
                currOcc[it-'a']++;
            }

            for(char ch = 'a';ch<='z';ch++){
                maxOcc[ch-'a'] = max(maxOcc[ch-'a'], currOcc[ch-'a']);
            }
        }

        for(i=0;i<n;i++){
            string toCheck = words1[i];
            vector<int>haveOcc(26,0);

            for(auto it : toCheck){
                haveOcc[it-'a']++;
            }

            bool be = true;
            for(char ch = 'a';ch<='z';ch++){
                if(maxOcc[ch-'a'] > haveOcc[ch-'a']){
                    be = false;
                    break;
                }
            }
            if(be) ans.push_back(toCheck);
        }
        return ans;
    }
};