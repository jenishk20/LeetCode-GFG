class Solution {
public:
    bool canFormWord(string word,map<char,int>letterQuant){
        
        for(auto it : word){
            letterQuant[it]--;
            if(letterQuant[it]<0){
                return false;
            }
        }
        return true;
    }
    
    int getScore(string word,map<char,int>&scoreMap){
        int ans =0;
        for(auto it : word){
            cout<<it<<" "<<scoreMap[it]<<endl;
            ans+=scoreMap[it];
        }
        return ans;
    }
    int recur(int idx,vector<string>&words,map<char,int>&scoreMap,map<char,int>&
             letterQuant){
        
        if(idx==words.size()) return 0;
        
        int op1 = recur(idx+1,words,scoreMap,letterQuant);
        int op2 = 0;
        
        if(canFormWord(words[idx],letterQuant)){
            
            for(auto it : words[idx]){
                letterQuant[it]--;
            }
            
            cout<<words[idx]<<" "<<getScore(words[idx],scoreMap)<<endl;
            op2 = getScore(words[idx],scoreMap) + recur(idx+1,words,scoreMap,letterQuant);    
            for(auto it : words[idx]){
                letterQuant[it]++;
            }
            
        }
        return max(op1,op2);
    }
    
    int dfs(vector<string>& ws, vector<int> &cnt, vector<int> &score, int i) {
    if (i >= ws.size()) return 0;
    auto skipGain = dfs(ws, cnt, score, i + 1), gain = 0, formed = 1;
    vector<int> cnt1(begin(cnt), end(cnt));
    for (auto ch : ws[i]) {
        if (--cnt1[ch - 'a'] < 0) formed = 0;
        gain += score[ch - 'a'];
    }
    return max(skipGain, formed ? 
        gain + dfs(ws, cnt1, score, i + 1) : 0);
}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        
        vector<int> cnt(26);
        for (auto ch : letters) ++cnt[ch - 'a'];
        return dfs(words, cnt, score, 0);
        map<char,int>scoreMap;
        map<char,int>letterQuant;
        
        int idx = 0;
        
        for(char ch = 'a';ch<='z';ch++){
            scoreMap[ch] = score[idx++]; 
            cout<<ch<<" "<<scoreMap[ch]<<endl;
        }
        
        for(auto it : letters){
            letterQuant[it]++;
        }
        
        return recur(0,words,letterQuant,scoreMap);
        
    }
};