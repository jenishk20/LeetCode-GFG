class Solution {
public:
    char kthCharacter(int k) {
        
       if(k==1) return 'a';
        
        int st = 1;
        
        while(st<k){
            st*=2;
        }
        
        int toFind = k-st/2;
        
        char ch = kthCharacter(toFind);
        return ch+1;
        
    }
};