class Solution {
public:
    int findComplement(int num) {
        int firstPos = 0;

        for(int i=31;i>=0;i--){
            if(num&(1<<i)){
                firstPos = i;
                break;
            }
        }
      
        int ans = 0;
        for(int i=firstPos;i>=0;i--){
            if(!(num&(1<<i))){
                ans |= (1<<i);
            }
        }
        return ans;
        
    }
};