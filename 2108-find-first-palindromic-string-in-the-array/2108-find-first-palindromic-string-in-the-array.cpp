class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        
        for(int i=0;i<words.size();i++)
        {
            string curr=words[i];
            reverse(words[i].begin(),words[i].end());
            if(curr==words[i])
                return curr;
        }
        return "";
    }
};