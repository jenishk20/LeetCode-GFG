class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
         vector<string>res;
         map<string,map<char,int>>ma;
        
        for(auto it : words){
            map<char,int>freq;
            for(auto it2 : it){
                freq[it2]++;
            }
            ma[it] = freq;
        }
        
        for(char ch = 'a';ch<='z';ch++){
            
            int ans = 1e9;
            for(auto it : words){
                bool be = false;
                for(auto it2 : ma[it]){
                    
                    if(it2.first==ch){
                        be = true;
                        ans = min(ans,it2.second);
                    }
                }
                if(!be){
                    ans = 1e9;
                    break;
                }
            }
            if(ans!=1e9){
                while(ans--) res.push_back(string(1,ch));
            }
        }
        return res;
    }
};