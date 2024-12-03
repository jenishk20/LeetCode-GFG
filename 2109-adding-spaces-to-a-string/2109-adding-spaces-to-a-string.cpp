class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int st = 0;

        string ans = "";
        int j = 0;
        
        for(int i=0;i<n;i++){
            if(j<spaces.size() and i == spaces[j]){
                j++;
                ans += " ";
                ans += s[i];
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};