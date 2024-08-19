class Solution {
public:
    int dp[1001][1001];
    int recur(int currA,int currC,int n){
        if(currA == n) return 0;
        if(currA > n) return 1e9;
        
        if(dp[currA][currC]!=-1) return dp[currA][currC];
        
        int op1 = 2 + recur(currA+currA,currA,n);
        int op2 = 1 + recur(currA+currC,currC,n);
        
        return dp[currA][currC] = min(op1,op2);
    }
    int minSteps(int n) {
        
        vector<int>fact(10001);
        fact[0] = 0;
        fact[1] = 0;
        fact[2] = 2;
        
        for(int i=3;i<=n;i++){
            
            int firstLargestFact = i/2;
            while(firstLargestFact>=1){
                if(i%firstLargestFact == 0){
                    
                    int stepsToReachFact = fact[firstLargestFact];
                    int paste = i/firstLargestFact - 1;
                    fact[i] = stepsToReachFact + paste + 1;
                    break;
                }
                else{
                    firstLargestFact--;
                }
            }
        }
        
        return fact[n];
      
    }
};