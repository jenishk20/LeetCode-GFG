class Solution {
public:
    map<int,int>ma;
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(ma.find(n) != ma.end()) return ma[n];
        return ma[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};