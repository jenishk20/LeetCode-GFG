class Solution {
    public:
   int dp[101][101];
    int solve(int ptr, int index, string& ring, string& key, int n, int m) {
        if (index >= m)
            return 0;
        if (dp[ptr][index] != -1)
            return dp[ptr][index];

        int steps = INT_MAX;
        for (int i = 0; i < ring.size(); i++)
            if (ring[i] == key[index])
                steps = min(steps, min(abs(i - ptr), n - abs(i - ptr)) + 1 +
                                       solve(i, index + 1, ring, key, n, m));
        return dp[ptr][index] = steps;
    }
    int findRotateSteps(string ring, string key) {
        
         int n = ring.size();
        int m = key.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, ring, key, n, m);
    }
};