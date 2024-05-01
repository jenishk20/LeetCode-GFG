class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i;
        bool be = false;
        for(i=0;i<word.size();i++){
            if(word[i]==ch){
                be = true;
                break;
            }
        }
        
        if(be)
        reverse(word.begin(),word.begin()+i+1);
        
        return word;
    }
};