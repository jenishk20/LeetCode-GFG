class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        int i,j;
        vector<vector<int>>vis(n,vector<int>(m+1,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        vis[sr][sc] = 1;
        int prev = image[sr][sc];
        while(!q.empty()){
            
            auto curr = q.front();
            image[curr.first][curr.second] = color;
            q.pop();
            for(int k = 0;k<4;k++){
                int nx = dx[k]+curr.first;
                int ny = dy[k]+curr.second;
                
                if(nx>=0 and ny>=0 and nx<n and ny<m and !vis[nx][ny]
                  and image[nx][ny]==prev){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            
        }
        return image;
    }
};