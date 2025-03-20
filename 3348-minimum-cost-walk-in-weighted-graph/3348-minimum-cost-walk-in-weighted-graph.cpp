class DSU{
public:
    vector<int>parent,andOfAllEdges;
    DSU(int n){
        parent.resize(n);
        andOfAllEdges.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(int i=0;i<n;i++){
            andOfAllEdges[i] = -1;
        }
    }

    int findParent(int k){

        if(k == parent[k]) return k;
        return parent[k] = findParent(parent[k]);
    }

    void merge(int u,int v,int wt){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv){
            andOfAllEdges[pu] &= wt;
            return;
        }
        
        parent[pu] = pv;
        if(andOfAllEdges[pv] == -1){
            andOfAllEdges[pv] = andOfAllEdges[pu] & wt;
        }
        else{
            andOfAllEdges[pv] &= andOfAllEdges[pu] & wt;
        }
    }

    int findAnd(int src, int dest){
        int pu = findParent(src);
        int pv = findParent(dest);
        if(pu == pv) return andOfAllEdges[pu];
        return -1;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        DSU dsu(n);
        vector<int>ans;

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dsu.merge(u,v,wt);
        }

        for(auto it : query){
            int src = it[0];
            int dest = it[1];
            int res = dsu.findAnd(src,dest);
            ans.push_back(res);
        }

        return ans;
    }
};