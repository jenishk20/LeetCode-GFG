class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        
        map<string,int>ma;
        for(auto it : bannedWords) ma[it]++;
        
        int cnt = 0;
        for(auto it : message){
            if(ma[it]>0) cnt++;
        }
        
        return cnt>=2;
    }
};