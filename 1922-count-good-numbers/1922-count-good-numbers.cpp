class Solution {
public:
    int mod = 1e9 + 7;
    long long pow(long long base,long long power){
        
        long long res = 1;
        
        while(power){
            
            if(power%2 == 0){
                base = (base * base) % mod;
                power/=2;
            }
            else{
                res = (res * base) % mod;
                power--;
            }
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        
        long long evenPos = ceil((double)n/2);
        long long primePos = n - evenPos;
        
        long long firstPower = pow(5,evenPos);
        long long secondPower = pow(4,primePos);
        
        return ( firstPower * secondPower ) % mod;
    }
};