class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.size();
        
        int i=0;
        int cnt = 0;
        
        for(i=0;i<n;i++){
            if(s[i]=='1') cnt++;
        }
        
        if(cnt==0){
            string res(n,'0');
            return res;
        }
        if(cnt==1){
            string res(n,'0');
            res[n-1] = '1';
            return res;
        }
        
        string res = "";
        int rem = n-cnt;
        cnt--;
        
        while(cnt--){
            res+='1';
        }
        while(rem--){
            res+='0';
        }
        
        res+='1';
        return res;
        
        
    }
};