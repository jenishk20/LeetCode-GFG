class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();

        int i=0;
        int j = n-1;

        while(i<j){
            if(isalpha(s[i]) and isalpha(s[j])){
                if(tolower(s[i]) == tolower(s[j])){
                    i++;
                    j--;
                }
                else{
                    return false;
                }
            }
            else if(isdigit(s[i]) and isdigit(s[j])){
                if(s[i] == s[j]){
                    i++;
                    j--;
                }
                else{
                    return false;
                }
            }
            else if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else return false;
        }
        return true;
    }
};