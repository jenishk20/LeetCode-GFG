class Solution {
public:
    int recur(int idx,string &s,int sign,int result){
        
        if(idx>=s.size() or s[idx]<'0' or s[idx]>'9'){
            return sign * result;
        }
        
        int curr = s[idx]-'0';
        
        if(result*1ll*10 + curr > INT_MAX){
            
            if(sign == -1) return INT_MIN;
            return INT_MAX;
        }
        return recur(idx+1,s,sign,result*10 + curr);
    }
    int myAtoi(string s) {
        
        int n = s.size();
        
        int i = 0;
        
        while(i<n and s[i] == ' ') i++;
        
        int sign = 1;
        
        if(s[i] == '-'){
            i++;
            sign = -1;
        }
        else if(s[i] == '+'){
            i++;
        }
        
        return recur(i,s,sign,0);
    }
};