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
        cout<<"Inside Score Map function "<<word<<endl;
        for(auto it : word){
            cout<<it<<" "<<scoreMap[it]<<endl;
            ans+=scoreMap[it];
        }
        return ans;
    }
    int recur(int idx,vector<string>&words,map<char,int>&letterQuant,map<char,int>&scoreMap){
        
        if(idx==words.size()) return 0;
        
        int op1 = recur(idx+1,words,letterQuant,scoreMap);
        int op2 = 0;
        
        if(canFormWord(words[idx],letterQuant)){
            
            for(auto it : words[idx]){
                letterQuant[it]--;
            }
            
            op2 = getScore(words[idx],scoreMap) + recur(idx+1,words,letterQuant,scoreMap);    
            
            for(auto it : words[idx]){
                letterQuant[it]++;
            }
            
        }
        return max(op1,op2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        map<char,int>scoreMap;
        map<char,int>letterQuant;
        
        int idx = 0;
        
        for(char ch = 'a';ch<='z';ch++){
            scoreMap[ch] = score[idx++]; 
        }
        
        for(auto it : letters){
            letterQuant[it]++;
        }
        
        return recur(0,words,letterQuant,scoreMap);
        
    }
};