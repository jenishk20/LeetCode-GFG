class Solution {
public:
    
    int dp[101][101];
    bool recur(int idx,int openCount,string s,int n){
        if(idx==n) return openCount == 0;
        
        bool ans = false;
        
        if(dp[idx][openCount]!=-1) return dp[idx][openCount];
        
        if(s[idx] == '*') {
            
            int op1 = recur(idx+1,openCount+1,s,n);
            int op2 = openCount>0?recur(idx+1,openCount-1,s,n):0;
            int op3 = recur(idx+1,openCount,s,n);
            
            ans |= op1 | op2 | op3;
        }
        else if(s[idx] =='('){
            ans = ans | recur(idx+1,openCount+1,s,n);
        }
        else{
            ans = ans | openCount>0?recur(idx+1,openCount-1,s,n):0;
        }
        return dp[idx][openCount] = ans;
    }
    bool checkValidString(string s) {
        
        memset(dp,-1,sizeof dp);
        return recur(0,0,s,s.size());
    }
};