class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n&1) return false;

        stack<int>open,wild;
        for(int i=0;i<n;i++){
            if(locked[i] == '0'){
                wild.push(i);
            }
            else{
                if(s[i] == '('){
                    open.push(i);
                }
                else{
                    if(open.empty() and wild.empty()){
                        return false;
                    }
                    if(!open.empty()){
                        open.pop();
                    }
                    else{
                        wild.pop();
                    }
                }
            }
        }

        while(!open.empty() and !wild.empty()){
            if(open.top()<wild.top()){
                open.pop();
                wild.pop();
            }
            else{
                return false;
            }
        }
        return wild.size()%2==0 and open.empty();
    }
};