class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int i;
        int ans = 0;

        for(int i=0;i<31;i++){
            int cnt = 0;
            for(auto it : candidates){
                if(it&(1<<i)){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};