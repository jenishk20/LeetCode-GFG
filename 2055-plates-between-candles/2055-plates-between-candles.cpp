class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        int n = s.size();
        vector<int>ans;
        
        vector<int>pfxCandle(n,-1),sfxCandle(n,-1);
        vector<int>pfxPlates(n);
        
        int i,cnt = 0;
        
        for(i=0;i<n;i++){
            if(s[i] == '*'){
                cnt++;
            }
            pfxPlates[i] = cnt;
        }
        
        int lastCandle = -1;
        for(i=0;i<n;i++){
            if(s[i] == '|'){
                lastCandle = i;
            }
            pfxCandle[i] = lastCandle;
        }
        
        lastCandle = -1;
        for(i=n-1;i>=0;i--){
            if(s[i] == '|'){
                lastCandle = i;
            }
            sfxCandle[i] = lastCandle;
        }
        
        for(auto it : queries){
            int st = it[0];
            int en = it[1];
            
            int rightOf = sfxCandle[st];
            int leftOf = pfxCandle[en];
            
            if(rightOf == -1 or leftOf == -1) {
                ans.push_back(0);
                continue;
            }
            if(rightOf<=leftOf){
                ans.push_back(pfxPlates[leftOf] - pfxPlates[rightOf]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
        
    }
};