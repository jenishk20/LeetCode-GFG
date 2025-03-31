class Solution {
public:
    const int mod = 1e9 + 7;
    int lcm(int a,int b){
        return (a*b)/(__gcd(a,b));
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long low = 0;
        long long high = 1e17;  
        long long ans = 0;

        while(low<=high){
            long long mid = (low + high)/2;
            long long mulsOfA = mid/a;
            long long mulsOfB = mid/b;

            long long mulsOfAB = mid/(lcm(a,b));
            long long total = mulsOfA + mulsOfB - mulsOfAB;
            if(total >= n){
                ans = mid%mod;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};