class Solution {
public:
    int timeRequiredToBuy(vector<int>& tick, int k) {
       
        int n=tick.size();
        
        queue<pair<int,int>>q;
        vector<int>ans(n);
            int i;
        for(i=0;i<n;i++)
        {
            q.push({i,tick[i]});
        }
        int time=1;
        while(!q.empty())
        {
            int c=q.front().first;
            int rem=q.front().second;
            q.pop();
            rem--;
            if(rem==0)
            {
                ans[c]=time;
            }
            else
            {
                q.push({c,rem});
            }
            time++;
            
        }
        return ans[k];
    }
};