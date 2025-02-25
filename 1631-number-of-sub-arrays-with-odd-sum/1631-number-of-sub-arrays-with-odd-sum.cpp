class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>pfx(n,0);
        pfx[0] = arr[0];

        for(int i=1;i<n;i++){
            pfx[i] = arr[i] + pfx[i-1];
        }
        
        int res = 0;
        int prevEven = 0;
        int prevOdd = 0;
        int mod = 1e9 + 7;

        for(int i=0;i<n;i++){
            if(pfx[i]&1){
                res = (res + prevEven + 1)%mod;
                prevOdd++;
            }
            else{
                res = (res + prevOdd)%mod;
                prevEven++;
            }
        }

        return res;
    }
};