class Solution {
public:
    bool isUgly(int n) {
     
        for(int i=2;i<=n and i<=6;i++){
            while(n%i==0){
                n/=i;
            }
        }

        if(n!=1) return false;
        
        return true;
    }
};