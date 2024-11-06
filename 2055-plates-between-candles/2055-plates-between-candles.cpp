class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int>sfxArray(n+1,0);
        vector<int>pipes;
        
        int lastPipe = n+1;

        for(int i=n-1;i>=0;i--){
            if(s[i] == '|'){
                sfxArray[i] = lastPipe;
                lastPipe = i;
                pipes.push_back(i);
            }
            else{
                sfxArray[i] = lastPipe;
            }
        }

        sort(pipes.begin(),pipes.end());

        vector<int>ans;

        for(auto it : queries){
            int st = s[it[0]] == '|' ? it[0] : sfxArray[it[0]];
            int en = it[1];
            
            if(pipes.empty()){
                ans.push_back(0);
                continue;
            }
            st = upper_bound(pipes.begin(),pipes.end(),st) - pipes.begin();
            en = upper_bound(pipes.begin(),pipes.end(),en) - pipes.begin();

            if(st > en){
                ans.push_back(0);
                continue;
            }

            en--;
            st--;

            int tot = en - st + 1;
            int rem = (pipes[en] - pipes[st] +1) - tot;
            ans.push_back(rem);
        }
        return ans;
    }
};