class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        
    int sum = 0;
    for(auto n: nums){
        int count = 0, mx = 0, t = 0;
        while(n){
            mx = max(mx, n%10);
            n = n/10;
            count++;
        }
        while(count){
            t = t*10 + mx;
            count--;
        }
        sum += t;
    }
    return sum;
        
    }
};