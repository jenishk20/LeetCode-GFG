class Solution {
    
private:
    map<string,int>levelOfString;
    vector<vector<string>>ans;
    
    void dfs(string word, vector<string>&seq,string beginWord){
    
        if(word == beginWord){
            
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        
        int currentSteps = levelOfString[word];
        for(int i=0;i<word.size();i++){
            
            char prev = word[i];
            for(char ch = 'a';ch<='z';ch++){
                
                word[i] = ch;
                
                if(levelOfString.find(word)!=levelOfString.end()){
                
                    if(levelOfString[word]+1 == currentSteps){
                        seq.push_back(word);
                        dfs(word,seq,beginWord);
                        seq.pop_back();
                    }
                }
                
            }
            word[i] = prev;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string>q;
        set<string>se;
        
        for(auto i:wordList){
            se.insert(i);
        }
        
        q.push(beginWord);
        levelOfString[beginWord] = 0;
        se.erase(beginWord);
        int st = 0;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int currentSteps = levelOfString[curr];
            for(int i=0;i<curr.size();i++){
                
                char prev = curr[i];
                for(char ch ='a';ch<='z';ch++){
                    curr[i] = ch;
                    
                    if(se.find(curr)!=se.end()){
                        q.push(curr);
                        levelOfString[curr] = currentSteps+1;
                        se.erase(curr);
                    }
                }
                curr[i] = prev;
            }   
        }
      
        if(levelOfString.find(endWord)!=levelOfString.end()){
          
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq,beginWord);
        }
        
        return ans;
        
    }
};