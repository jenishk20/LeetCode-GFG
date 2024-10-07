class Solution {
public:
    int minLength(string s) {
        
        int n = s.size();
        stack<char>se;
        int removed = 0;
        
        for(int i=0;i<n;i++){
            
            if(s[i] == 'B'){
                if(!se.empty() and se.top() == 'A'){
                    se.pop();
                    removed+=2;
                    continue;
                }
            }
            if(s[i] == 'D'){
                if(!se.empty() and se.top() == 'C'){
                    se.pop();
                    removed+=2;
                    continue;
                }
            }
            se.push(s[i]);
        }
        
        return n - removed;
    }
};