class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        int st = 1;
        n--;
        while(n--){
            ans += (4*st);
            st++;
        }
        return ans;
    }
};