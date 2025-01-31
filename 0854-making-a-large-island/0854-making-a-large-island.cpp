class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    class DSU{
        public:
        map<pair<int,int>,pair<int,int>>parent;
        map<pair<int,int>,int>sz;

        DSU(int n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    parent[{i,j}] = {i,j};
                    sz[{i,j}] = 1;
                }
            }
        }

        int findSize(pair<int,int>p1){
            return sz[findParent(p1)];
        }

        pair<int,int>findParent(pair<int,int>toCheck){
            if(toCheck == parent[toCheck]){
                return toCheck;
            }
            return parent[toCheck] = findParent(parent[toCheck]);
        }

        void merge(pair<int,int>p1,pair<int,int>p2){
            pair<int,int> pu = findParent(p1);
            pair<int,int> pv = findParent(p2);

            if(pu == pv) return;

            int sz1 = sz[pu];
            int sz2 = sz[pv];

            if(sz1>sz2){
                parent[pv] = pu;
                sz[pu] += sz[pv];
            }
            else{
                parent[pu] = pv;
                sz[pv] += sz[pu];
            }
        }
    };

    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,DSU &dsu){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;

            if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid.size() and !vis[nx][ny] and grid[nx][ny] == 1){
                
               dsu.merge({i,j},{nx,ny});
               dfs(nx,ny,grid,vis,dsu); 
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i,j;
        int maxi = 0;

        int res = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        DSU dsu(n);

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    dfs(i,j,grid,vis,dsu);
                }
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 0){
                    set<pair<int,int>>se;

                    for(int k=0;k<4;k++){
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;

                        if(nx>=0 and ny>=0 and nx<n and ny<n and grid[nx][ny]){
                            se.insert(dsu.findParent({nx,ny}));
                        }
                    }
                    int ans = 1;
                    for(auto it : se){
                        // cout<<it.first<<" "<<it.second<<endl;
                        ans += dsu.findSize(it);
                    }
                    res = max(res,ans);
                }
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                res = max(res,dsu.findSize({i,j}));
            }
        }

        return res;
    }
};