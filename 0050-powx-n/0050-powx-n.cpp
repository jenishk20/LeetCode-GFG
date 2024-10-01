class Solution {
public:
    double myPow(double x, int n) {
        
        double res = 1;
        double base = x;
        bool neg = false;
        
        long power = abs(n);
        
        if(n<0){
            neg = true;
        }
     
        while(power){
            
            if(power%2==0){
                base *= base;
                power/=2;
            }
            else{
                res *= base;
                power--;
            }
            cout<<power<<" "<<res<<endl;
        }
        return neg ? 1/res : res;
    }
};