class Solution {

private:
    vector<bool>isPrime;
    vector<int>primes;

    void generatePrimes(){
        isPrime.resize(1e6+1,1);
        isPrime[1] = 0;
        for(int i=2;i<=sqrt(1e6);i++){
            if(isPrime[i]){
                for(int j = i*i;j<=1e6;j+=i){
                    isPrime[j] = false;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        generatePrimes();

        vector<int>ans(2,-1);
        int prev = -1;
        int minDiff = 1e9;
        for(int i = left;i<=right;i++){
            if(isPrime[i]){
                if(prev != -1){
                    int diff = i-prev;
                    if(diff < minDiff){
                        minDiff = diff;
                        ans[0] = prev;
                        ans[1] = i;
                    }
                    prev = i;
                }
                else{
                    prev = i;
                }
            }
        }
        return ans;
    }
};