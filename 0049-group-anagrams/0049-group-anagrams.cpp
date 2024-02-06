class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
       
        map<string,vector<string>>ma;
     
        for(int i=0;i<strs.size();i++)
        {
            string t=strs[i];
            sort(t.begin(),t.end());
            ma[t].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:ma)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};