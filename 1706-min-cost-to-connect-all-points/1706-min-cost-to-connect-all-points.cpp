class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>inMST(n);
        pq.push({0,0});
        int mst = 0;
        int edges = 0;
        
        while(edges < n){
            auto curr = pq.top();
            pq.pop();

            if(inMST[curr.second]) continue;

            inMST[curr.second] = 1;
            mst += curr.first;
            edges++;

            for(int i=0;i<n;i++){
                if(!inMST[i]){
                    int xwt = abs(points[i][0] - points[curr.second][0]);
                    int ywt = abs(points[i][1] - points[curr.second][1]);
                    pq.push({xwt + ywt,i});
                }
            }
        }
        return mst;
    }
};