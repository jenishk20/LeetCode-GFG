class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int cnt = 0;
        for(int i=31;i>=0;i--){
            if(goal&(1<<i) and !(start&(1<<i))) cnt++;
            else if(!(goal&(1<<i)) and (start&(1<<i))) cnt++;
        }
        return cnt;
    }
};