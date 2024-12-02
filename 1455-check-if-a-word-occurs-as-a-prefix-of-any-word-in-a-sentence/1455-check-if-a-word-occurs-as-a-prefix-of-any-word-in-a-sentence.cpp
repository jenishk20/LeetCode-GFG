class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n = sentence.size();
        
        string currWord = "";
        int st = 1;
        
        for(int i=0;i<n;i++){
            if(sentence[i] == ' '){
                currWord = "";
                st++;
            }
            else{
                currWord += sentence[i];
                if(currWord == searchWord) return st;
            }
        }
        
        return -1;
    }
};