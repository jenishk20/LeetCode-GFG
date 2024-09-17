class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        string temp = s1 + ' ' + s2;
        
        map<string,int>ma;
        string str = "";
        vector<string>ans;
        
        for(char x : temp){
            if(x==' '){
                ma[str]++;
                str="";
            }
            else str+=x;
        }
        ma[str]++;
        
        for(auto it : ma){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    
    }
};