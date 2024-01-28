class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int i,j;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        
        int currDis = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                int currx = q.front().first;
                int curry = q.front().second;
                q.pop();
                for(int  k =0;k<4;k++){
                    
                    int nx = dx[k] + currx;
                    int ny = dy[k] + curry;
                    
                    if(nx>=0 and ny>=0 and nx<n and ny<m and !vis[nx][ny]
                      and dis[nx][ny] == INT_MAX){
                        vis[nx][ny] = 1;
                        dis[nx][ny] = 1+currDis;
                        q.push({nx,ny});
                    }
                }
                
            }
            currDis++;
        }
        return dis;
    }
};