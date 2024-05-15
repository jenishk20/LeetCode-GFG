class Solution {
public:
    vector<int> roww = {0,0,-1,1};
    vector<int> coll = {-1,1,0,0};

    void bfs(vector<vector<int>>& grid,vector<vector<int>>& score,int n) {
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j]) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            int s = score[x][y];

            for(int i =0; i < 4; i++){
                int newX = x + roww[i];
                int newY = y + coll[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s) { 

                    score[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }
    }

   int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n=grid.size();
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({0,{i,j}});
                    dis[i][j]=0;
                }
            }
        }
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!q.empty()){
            int i=q.top().second.first,j = q.top().second.second, d=q.top().first;
            q.pop();
            
            for(auto dir:dirs){
                int ni=i+dir[0], nj=j+dir[1];
                
                if(ni>=0 && ni<n && nj>=0 && nj<n && d+1<dis[ni][nj]){
                    q.push({d+1,{ni,nj}});
                    dis[ni][nj]=d+1;
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>> nq;
        nq.push({dis[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        int mx=0;
        while(!nq.empty()){
            int safe= nq.top().first, i=nq.top().second.first, j=nq.top().second.second;
            nq.pop();
            
            if(i==n-1 && j==n-1){
                
                return safe;
            }
            for(auto dir:dirs){
                int ni=i+dir[0], nj=j+dir[1];
                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj]){
                    nq.push({min(safe,dis[ni][nj]),{ni,nj}});
                    vis[ni][nj]=1;
                }
            }
        }
        
        return mx;
    }
};