class Solution {
public:
    bool isUgly(int n) {
        
        if(n==0) return 0;
        
        while(n%2==0){
            n/=2;
        }
        
        for(int i=3;i<=n and i<=6;i+=2){
            while(n%i==0){
                n/=i;
            }
        }

        if(n!=1) return false;
        
        return true;
    }
};