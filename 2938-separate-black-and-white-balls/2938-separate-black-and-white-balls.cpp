class Solution {
public:
    long long minimumSteps(string s) {
        
        long long cnt = 0;
        int n = s.size();
        
        int lastOne = n;
        
        for(int i=n-1;i>=0;i--){
            
            if(s[i] == '1'){
                cnt += (lastOne - i - 1);
                lastOne--;
            }
        }
        return cnt;
        
        
    }
};