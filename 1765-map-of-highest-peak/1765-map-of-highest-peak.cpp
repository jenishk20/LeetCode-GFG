class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int n = isWater.size();
        int m = isWater[0].size();
        
        int i,j;
        
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(isWater[i][j]){
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int nx = dx[k] + curr.first;
                int ny = dy[k] + curr.second;
                
                if(nx>=0 and ny>=0 and nx<n and ny<m and dis[nx][ny] == -1){
                    dis[nx][ny] = 1 + dis[curr.first][curr.second];
                    q.push({nx,ny});
                }
            }
            
        }
        
        return dis;
        
        
    }
};