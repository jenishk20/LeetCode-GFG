class DSU{
    public:
    vector<int>parent,nodesInComp, edgesInComp;
    DSU(int n){

        parent.resize(n);
        nodesInComp.resize(n,1);
        edgesInComp.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void merge(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv){
            edgesInComp[pv]++;
            return;
        }

        parent[pu] = pv;
        edgesInComp[pv] += edgesInComp[pu] + 1;
        nodesInComp[pv] += nodesInComp[pu];
    }

    pair<int,int>findResult(int u){
        return {edgesInComp[u],nodesInComp[u]};
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        DSU dsu(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            dsu.merge(u,v);
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i] == i){
                auto res = dsu.findResult(i);
                cnt += (res.second*(res.second-1) == 2*res.first);
            }
        }
        return cnt;
    }
};