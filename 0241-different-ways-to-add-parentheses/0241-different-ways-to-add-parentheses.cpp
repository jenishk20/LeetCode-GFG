class Solution {
public:
    vector<int>recur(string inp){
        vector<int>result;
        
        for(int i=0;i<inp.size();i++){
            if(inp[i] == '*' || inp[i] == '-' || inp[i] == '+'){
                vector<int>lResults = recur(inp.substr(0,i));
                vector<int>rResults = recur(inp.substr(i+1));
                
                for(auto it : lResults){
                    for(auto it2 : rResults){
                        if(inp[i] == '+') result.push_back(it + it2);
                        else if(inp[i] == '-') result.push_back(it - it2);
                        else if(inp[i] == '*') result.push_back(it*it2);
                    }
                }
            }
        }
        
        if(result.empty()){
            result.push_back(stoi(inp));
        }
        
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return recur(expression);
    }
};