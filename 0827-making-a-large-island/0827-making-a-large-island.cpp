class DSU{
public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    int findSize(int node){
        int pu = findPar(node);
        return size[pu];
    }
    void unioni(int u,int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
        else if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
    }
};

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i,j,k;


        DSU dsu(n*m);

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]){
                            int currNumber = i*m+j;
                            int newNumber = nx*m+ny;
                            dsu.unioni(currNumber,newNumber);
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(i=0;i<n;i++){

            for(j=0;j<m;j++){
                if(grid[i][j] == 0){
                      set<int>compoParents;
                      for(int k=0;k<4;k++){
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]){
                            int newNumber = nx*m+ny;
                            compoParents.insert(dsu.findPar(newNumber));
                        }
                    }
                    int total = 0;
                    for(auto it : compoParents){
                        total += dsu.findSize(it);
                    }
                    ans = max(ans,total+1);
                }
            }
        }
        
        for(i=0;i<n*m;i++){
            int sz = dsu.findSize(i);
            ans = max(ans,sz);
        }
        return ans;
    }
};