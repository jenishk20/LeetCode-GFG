class DSU{
private:
    vector<int>sz,parent;
public:
    DSU(int n){
        sz.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            sz[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unioni(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu == pv) return;
        
        if(sz[pu] > sz[pv]){
            sz[pu] += sz[pv];
            parent[pv] = pu;
        }
        else{
            sz[pv] += sz[pu];
            parent[pu] = pv;
        }
    }
    
    int sizeOfCompo(int node){
        return sz[node];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        DSU dsu(1001);
        
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                
                if(stones[i][0] == stones[j][0]  or stones[i][1] == stones[j][1]){
                    dsu.unioni(i,j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<=1000;i++){
            if(dsu.findParent(i) == i) cnt += dsu.sizeOfCompo(i)-1;
        }
        return cnt;
    }
};