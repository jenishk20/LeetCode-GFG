class Solution {
public:
    void recur(int st,string &s,string curr,vector<string>&wordDict,vector<string>&ans){
        
        if(st==s.size()){
            curr.pop_back();
            ans.push_back(curr);
        }
        
        string currFormation = "";
        for(int i=st;i<s.size();i++){
            
            currFormation.push_back(s[i]);
            
            if(find(wordDict.begin(),wordDict.end(),currFormation)!=wordDict.end()){
                
                recur(i+1,s,curr+currFormation+" ",wordDict,ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string>ans;
        string curr="";
        
        recur(0,s,curr,wordDict,ans);
        return ans;
    }
};