class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        int i=0;
        while(i<n/2){
            if(s[i] != s[n-i-1]) return false;
            i++;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        vector<string> res,res1;
        res.push_back("");
        res1.push_back("");
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++) {
            for(int j = i; j < s.length(); j++) {
                res.push_back(s.substr(i, j-i+1));
            }
        }

        for(int i = 0; i < t.length(); i++) {
            for(int j = i; j < t.length(); j++) {
                res1.push_back(t.substr(i, j-i+1));
            }
        }

        for(auto it : res){
            for(auto it2 : res1){
                string temp = it;
                temp += it2;
                if(isPalindrome(temp)){
                    ans = max(ans,(int)temp.size());
                }
            }
        }

        return ans;
    }
};