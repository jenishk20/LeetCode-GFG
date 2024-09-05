class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumOfExistingRolls = accumulate(rolls.begin(),rolls.end(),0);
        int unknownSum = mean*(n+m) - sumOfExistingRolls;

        int maxUnknownSum = n*6;
        if(unknownSum > maxUnknownSum  || unknownSum < n) return {};

        if(unknownSum == maxUnknownSum) return vector<int>(n,6);

        if(unknownSum%n == 0) return vector<int>(n,unknownSum/n);

        
        int part = unknownSum / n, rem = unknownSum % n;
        vector<int> ans(n, part);
        for (int i = 0; i < rem; ++i) 
            ++ans[i];
        return ans;
    }
};