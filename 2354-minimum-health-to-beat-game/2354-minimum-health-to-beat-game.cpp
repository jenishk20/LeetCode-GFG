class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 1e18;
        long long totalSum = accumulate(damage.begin(),damage.end(),0ll);
        int i;
        int n = damage.size();
        int windowSum = 0;

        for(i=0;i<n;i++){
            long long remSum = totalSum - damage[i];
            ans = min(ans, remSum+1+(armor<damage[i]?damage[i]-armor:0ll));
        }
        return ans;
    }
};