class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.size();
        
        string res = "";
        stack<pair<char,int>>se;
        vector<int>toBeRemoved;
        for(int i=0;i<n;i++){
            
            if(s[i] == ')'){
                
                if(!se.empty()){
                    se.pop();
                }
                else{
                    toBeRemoved.push_back(i);
                }
                
            }
            else if(s[i] == '('){
                se.push({s[i],i});
            }
        }
        
        while(!se.empty()){
            toBeRemoved.push_back(se.top().second);
            se.pop();
        }

        for(int i=0;i<n;i++){
            if(find(toBeRemoved.begin(),
                    toBeRemoved.end(),i)==
               toBeRemoved.end()){
                res+=s[i];
            }
        }
       
        return res;
    }
};