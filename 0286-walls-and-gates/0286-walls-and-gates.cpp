class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int n = rooms.size();
        int m = rooms[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int i,j;
        queue<pair<int,int>>q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(rooms[i][j] == 0) q.push({i,j});
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = dx[k] + curr.first;
                int ny = dy[k] + curr.second;
                if(nx>=0 and ny>=0 and nx<n and ny<m and rooms[curr.first][curr.second] + 1 < rooms[nx][ny] and rooms[nx][ny] != -1){
                    rooms[nx][ny] = 1 + rooms[curr.first][curr.second];
                    q.push({nx,ny});
                }
            }
        }
    }
};