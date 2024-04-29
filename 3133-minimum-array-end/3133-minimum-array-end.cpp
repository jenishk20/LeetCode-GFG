class Solution {
public:
    long long minEnd(int n, int x) {
        
        long long res = x;
       
        
        long long positionOfN = 1;
        
        for(long long st = 1 ; positionOfN<n;st<<=1){
            
            if((x&st)==0){
                
                if(((n-1)&positionOfN)){
                    res+=st;
                }
                positionOfN<<=1;
            }
            
        }
        
        return res;
        
    }
};