using pii = pair<int,int>;
using piii = pair<int,pii> ;
class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        int i,j;
        
        priority_queue<piii,vector<piii>,greater<piii>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            
            int maxDiffTillNow = pq.top().first;
            auto idx = pq.top().second;
            pq.pop();
            
            for(int k=0;k<4;k++){
                int nx = dx[k] + idx.first;
                int ny = dy[k] + idx.second;
                
                if(nx>=0 and ny>=0 and nx<n and ny<m){
                    int diff = abs(heights[nx][ny] - heights[idx.first][idx.second]);
                    
                    int newEffort = max(diff,maxDiffTillNow);
                    
                    if(newEffort < dist[nx][ny] ){
                        dist[nx][ny] = newEffort;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
            
        }
        
        return dist[n-1][m-1];
    }
};