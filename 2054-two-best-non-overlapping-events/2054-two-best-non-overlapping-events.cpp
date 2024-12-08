class Solution {
public:
    int dp[100001][2];
    int recur(vector<vector<int>>&events,int i,int cnt){
        if(i>=events.size() or cnt == 2) return 0;

        int low = 0;
        int high = events.size()-1;
        int nextBest = events.size();

        if(dp[i][cnt] != -1) return dp[i][cnt];
        
        while(low<=high){
            int ans = (low+high)/2;
            if(events[ans][0]>events[i][1]){
                nextBest = ans;
                high = ans-1;
            }
            else{
                low = ans+1;
            }
        }

        int take = events[i][2] + recur(events,nextBest,cnt+1);
        int notTake = recur(events,i+1,cnt);
        return dp[i][cnt] = max(take,notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        memset(dp,-1,sizeof dp);
        return recur(events,0,0);
    }
};