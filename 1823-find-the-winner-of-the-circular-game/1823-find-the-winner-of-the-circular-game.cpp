class Solution {
public:
    int recur(int n,int k){
        if(n==1) return 0;
        
        int idx = recur(n-1,k);
        idx = (idx + k)%n;
        return idx;
    }
    int findTheWinner(int n, int k) {
        
        return 1 + recur(n,k);
    }
};