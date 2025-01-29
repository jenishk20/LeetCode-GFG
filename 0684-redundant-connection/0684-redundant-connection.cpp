class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
    }

    int findParent(int x){
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void merge(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        parent[pu] = pv;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        DSU dsu(n+1);
        vector<int>ans(2);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int pu = dsu.findParent(u);
            int pv = dsu.findParent(v);
            if(pu == pv){
                ans[0] = u;
                ans[1] = v;
            }
            else{
                dsu.merge(u,v);
            }
        }
        return ans;
    }
};