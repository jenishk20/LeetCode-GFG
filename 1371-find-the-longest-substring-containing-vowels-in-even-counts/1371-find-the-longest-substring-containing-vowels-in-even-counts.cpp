class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<string,int>ma;
        
        int n = s.size();
        vector<int>bitMask(5,0);
        
        string currState = "00000";
        ma[currState] = -1;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(s[i] == 'a') bitMask[0] = (bitMask[0] + 1)%2;
            if(s[i] == 'e') bitMask[1] = (bitMask[1] + 1)%2;
            if(s[i] == 'i') bitMask[2] = (bitMask[2] + 1)%2;
            if(s[i] == 'o') bitMask[3] = (bitMask[3] + 1)%2;
            if(s[i] == 'u') bitMask[4] = (bitMask[4] + 1)%2;
            
            currState = "";
            for(int j=0;j<5;j++){
                currState += to_string(bitMask[j]);
            }
            
            if(ma.find(currState)!=ma.end()){
                ans = max(ans,i-ma[currState]);
            }
            else{
                ma[currState] = i;
            }
        }
        return ans;
    }
};