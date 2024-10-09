class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.size();
        int i,j;
        
        stack<int>se;
        
        int cc = 0;
        vector<int>isDone(n+1,0);
        
        for(i=0;i<n;i++){
            
            if(s[i] ==  '('){
                se.push(i);
            }
            else{
                if(se.empty()){
                    cc++;
                }
                else{
                    se.pop();
                }
            }
        }
        return cc + se.size();
    }
};