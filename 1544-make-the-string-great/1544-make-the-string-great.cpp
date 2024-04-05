class Solution {
public:
    string makeGood(string s) {
        
        stack<char>se;
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            se.push(s[i]);
            
            while(!se.empty() && (s[i+1]+32 == se.top() || 
                 s[i+1]-32 == se.top())){
                se.pop();
                i++;
            }
            
        }
        
        string res = "";
        while(!se.empty()){
            res+=se.top();
            se.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};