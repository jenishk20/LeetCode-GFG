class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>ma;

        for(auto it : banned) ma[it]++;

        int sum = 0;
        int cnt = 0;

        for(int i=1;i<=n;i++){
            if(!ma.count(i)){
                sum += i;
                if(sum<=maxSum) cnt++;
            }
        }

        return cnt;
    }
};