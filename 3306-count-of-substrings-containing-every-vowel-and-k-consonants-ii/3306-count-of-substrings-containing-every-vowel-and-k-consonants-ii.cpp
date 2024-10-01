class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        
        int n = word.size();
        int i,j;
        
        unordered_map<char,long long>vowels;
        
        i=0,j=0;
        
        long long cnt = 0;
        long long conso = 0;
        
        vector<int>nextCon(n);
        int last = n;
        
        for(int i=n-1;i>=0;i--){
            nextCon[i] = last;
            
            if(!isVowel(word[i])) last = i;
        }
        
        while(j<n){
            
            if(isVowel(word[j])){
                vowels[word[j]]++;
            }
            else{
                conso++;
            }
            
            while(conso > k){
                
                if(isVowel(word[i])){
                    vowels[word[i]]--;
                    if(vowels[word[i]] == 0) vowels.erase(word[i]);
                }
                
                else{
                   conso--;
                }
                
                i++;
            }
            
            
            if(vowels.size() == 5 and conso == k){
                
                while(vowels.size() == 5 and conso == k){
                    
                    cnt += nextCon[j] - j;
                    if(isVowel(word[i])){
                        vowels[word[i]]--;
                        if(vowels[word[i]] == 0) vowels.erase(word[i]);
                    }
                    else{
                       conso--;
                    }
                    i++;
                }             
            }
             
            j++;
        }
        
        return cnt;
    }
};