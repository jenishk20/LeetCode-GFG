class DSU{
public:
    vector<int>parent,rank;
    DSU(int n){ 
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void merge(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pu] = pv;
        }
        else{
            rank[pu]++;
            parent[pu] = pv;
        }
    }
};
class Solution {
public:
    int intersect(unordered_set<int>&a,unordered_set<int>&b){
        int cnt = 0;
        for(int i=1;i<=100;i++){
            if(a.count(i) and b.count(i)) cnt++;
        }
        return cnt;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        
        int n = properties.size();
        int m = properties[0].size();
        int i,j;
        DSU dsu(n+1);

        vector<unordered_set<int>>v(n+1);
        for(int i=0;i<n;i++){
            for(auto &it : properties[i]) {
                v[i].insert(it);
            }
        }

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(i!=j){
                    int val = intersect(v[i],v[j]);
                    if(val>=k){
                       dsu.merge(i,j);
                    }
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
           if(i == dsu.parent[i]) cnt++;
        }
        return cnt;
    }
};