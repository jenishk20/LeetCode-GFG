class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        vector<string>ans;
        
        int n = words.size();
        int i,j;
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j and words[j].find(words[i])!=string::npos and find(ans.begin(),ans.end(),words[i]) == ans.end()){
                    ans.push_back(words[i]);
                }
            }
        }
        return ans;
    }
};