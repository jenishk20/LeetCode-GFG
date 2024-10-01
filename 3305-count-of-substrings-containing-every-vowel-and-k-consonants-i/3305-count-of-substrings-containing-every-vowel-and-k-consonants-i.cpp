class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int countOfSubstrings(string word, int k) {
        
        int n = word.size();
        int i,j;
        
        map<char,int>vowels;
        
        
        vector<int>nextCon(n);
        int last = n;
        
        for(int i=n-1;i>=0;i--){
            nextCon[i] = last;
            
            if(!isVowel(word[i])) last = i;
        }
        
        i=0,j=0;
        
        int cnt = 0;
        int conso = 0;
        
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
                
                
//                 int prevBegin = i;
                
//                 map<char,int>tempVowels = vowels;
                
//                 while(i<j and tempVowels.size() == 5){
//                     cnt++;
//                     tempVowels[word[i]]--;
//                     if(tempVowels[word[i]] == 0) tempVowels.erase(word[i]);
//                     cout<<tempVowels.size()<<endl;
//                     i++;
                    
//                 }
                
//                 i = prevBegin;
             
            }
             
            j++;
        }
        
        return cnt;
    }
};