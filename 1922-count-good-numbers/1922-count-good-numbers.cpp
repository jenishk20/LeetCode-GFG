class Solution {
public:
    int mod = 1e9 + 7;
    long long pow(long long base,long long power){
        
        if(power == 0) return 1;
        
        if(power%2 == 0) return pow((base*base)%mod,power/2);
        
        return (base * pow(base,power-1))%mod;
    }
    int countGoodNumbers(long long n) {
        
        long long evenPos = ceil((double)n/2);
        long long primePos = n - evenPos;
        
        long long firstPower = pow(5,evenPos);
        long long secondPower = pow(4,primePos);
        
        return ( firstPower * secondPower ) % mod;
    }
};