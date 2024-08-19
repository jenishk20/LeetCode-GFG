class Solution {
public:
    int recur(int currA,int currC,int n){
        if(currA == n) return 0;
        if(currA > n) return 1e9;
        
        int op1 = 2 + recur(currA+currA,currA,n);
        int op2 = 1 + recur(currA+currC,currC,n);
        
        return min(op1,op2);
    }
    int minSteps(int n) {
        
        if(n==1) return 0;
        
        int currA = 1;
        int currC = 1;
        
        return 1 + recur(currA,currC,n);
    }
};