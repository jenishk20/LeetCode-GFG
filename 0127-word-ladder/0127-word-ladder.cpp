class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          set<string>se;
        queue<pair<string,int>>q;
        
        q.push({beginWord,1});
        
        for(auto i:wordList){
            se.insert(i);
        }
        
        
        while(!q.empty()){
            
            
            string curr = q.front().first;
            int steps = q.front().second;
            
            if(curr == endWord){
                return steps;
            }
            q.pop();
            
            for(int i=0;i<curr.size();i++){
                for(char ch = 'a';ch<='z';ch++){
                    char prev = curr[i];
                    curr[i] = ch;
                   // cout<<curr<<endl;
                    if(se.find(curr)!=se.end()){
                        se.erase(curr);
                        q.push({curr,steps+1});
                    }
                    curr[i] = prev;
                }
            }
        }
        
        return 0;
    }
};